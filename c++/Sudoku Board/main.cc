#include <iostream>
#include <iomanip>
#include <bitset>
#include "stack.h"

using namespace std;

uint16_t board[9][9];                       // the board
const uint16_t FILLED_MASK  = 0x2000;       // cell filled
const uint16_t VALUE_MASK   = 0x000F;       // cell int value 
const uint16_t ALLOWED_MASK = 0x1FF0;       // allowed digits in cell

uint8_t singleValueLocation;
Stack<uint8_t> stack;                       // the stack

// Read the input
void read_board(uint16_t board[9][9])
{
    char ch;
    int r;
    int c;

    // read it
    for (r=0; r<9; r++)
    {
        for (c=0; c<9; c++)
        {
            cin >> ch;
            if (ch == '.')
            {
                board[r][c] = 0;
            }
            else
            {
                board[r][c] = ch - '0';     // convert to int
                board[r][c] |= FILLED_MASK;
            }
        }
    }
}

// Find allowed digits for bit
void find_allowed_digits(uint16_t board[9][9], int row, int col)
{
    int r;
    int c;
    int i;
    unsigned int value;
    unsigned int allowedBit;

    int allowed[9] = {true, true, true, true, true, true, true, true, true};

    // start at given row
    for (c=0; c<9; c++)
    {
        if ((board[row][c] & FILLED_MASK) != 0)
        {
            value = board[row][c] & VALUE_MASK;
            allowed[value-1] = false;
        }
    }

    // next the given column
    for (r=0; r<9; r++)
    {
        if ((board[r][col] & FILLED_MASK) != 0)
        {
            value = board[r][col] & VALUE_MASK;
            allowed[value-1] = false;
        }
    }

    // now the given 3x3
    for (r=((row/3)*3); r<(((row/3)+1)*3); r++)
    {
        for (c=((col/3)*3); c<(((col/3)+1)*3); c++)
        {
            if ((board[r][c] & FILLED_MASK) != 0)
            {
                value = board[r][c] & VALUE_MASK;
                allowed[value-1] = false;
            }
        }
    }

    // Start at lowest bit and shift it up
    allowedBit = 0x0010;
    board[row][col] &= (~ALLOWED_MASK);
    for (i=0; i<9; i++)
    {
        if (allowed[i])
        {
            board[row][col] |= allowedBit;
        }
        // shift up for next digit
        allowedBit <<= 1;
    }
}

// Find all allowed digits
void find_all_allowed_digits(uint16_t board[9][9])
{
    int r;
    int c;

    for (r=0; r<9; r++)
    {
        for (c=0; c<9; c++)
        {
            find_allowed_digits(board, r, c);
        }
    }
}

// Print the board
void print_board(uint16_t board[9][9])
{
    int r;
    int c;
    unsigned int value;
    unsigned int allowed;
    unsigned int filled;

    int spaceCount = 0;
    int rowCount = 0;

    for (r=0; r<9; r++)
    {
        for (c=0; c<9; c++)
        {
            value = board[r][c] & VALUE_MASK;
            cout << value << " ";

            spaceCount++;
            if (spaceCount == 3)
            {
                cout << " ";
                spaceCount = 0;
            }

        }
        cout << endl;
        rowCount++;
        if (rowCount == 3)
        {
            cout << endl;
            rowCount = 0;
        }
    }
    system("pause");
}

// Algorithm 2: Finding best empty cell

bool find_best_cell(uint16_t board[9][9])
{
    int r;
    int c;
    int rx;
    int cx;

    int low = 10;
    int rBest;
    int cBest;
    int count = 0;

    unsigned int bitCheck;

    // Allow all digits initially
    for (r=0; r<9; r++)
    {
        for (c=0; c<9; c++)
        {
            if ((board[r][c] & FILLED_MASK) == 0)
            {
                board[r][c] |= ALLOWED_MASK;
            }
        }
    }
    // Remove invalid choices
    for (r=0; r<9; r++)
    {
        for (c=0; c<9; c++)
        {
            if ((board[r][c] & FILLED_MASK) != 0)
            {
                uint16_t val = (board[r][c] & VALUE_MASK);
                uint16_t bit = 0x10 << (val - 1);

                for (cx=0; cx<9; cx++)
                {
                    if ((board[r][cx] & FILLED_MASK) == 0)
                    {
                        board[r][cx] &= (~bit);
                    }
                }
                for (rx=0; rx<9; rx++)
                {
                    if ((board[rx][c] & FILLED_MASK) == 0)
                    {
                        board[rx][c] &= (~bit);
                    }
                }
                for (rx=((r/3)*3); rx<((r/3)+1)*3; rx++)
                {
                    for (cx=((c/3)*3); cx<((c/3)+1)*3; cx++)
                    {
                        if ((board[rx][cx] & FILLED_MASK) == 0)
                        {
                            board[rx][cx] &= (~bit);
                        }
                    }
                }

            }
        }
    }

    // for each unfilled cell
    for (r=0; r<9; r++)       
    {
        for (c=0; c<9; c++)
        {
            count = 0;
            if ((board[r][c] & FILLED_MASK) == 0)
            {
                // Count bits set to 1
                // Start at lowest bit and shift it up
                bitCheck = 0x0010;
                for (int i=0; i<9; i++)
                {
                    if ((board[r][c] & bitCheck) != 0)
                    {
                        count++;
                    }
                    // shift up for next digit
                    bitCheck <<= 1;
                }

                if (count < low)
                {
                    low = count;
                    rBest = r;
                    cBest = c;
                }
            }
        }
    }
    
    if (low == 10)
    {
        return false;
    }

    board[rBest][cBest] |= FILLED_MASK;     // mark as filled in
    singleValueLocation = rBest*16+cBest;
    stack.push(singleValueLocation);        // push to stack

    return true;
}

// Algorithm 1: Main Sudoku algorithm

void solve_board(uint16_t board[9][9])
{
    // Find best empty cell and place on stack
    bool bestEmpty = find_best_cell(board);

    while (bestEmpty)
    {
        // r and c are top of stack
        singleValueLocation = stack.peek();
        uint8_t r = int(singleValueLocation / 16);
        uint8_t c = singleValueLocation & 0x0F;

        unsigned int allowance;
        unsigned int i;
        // Select next allowed digit for board[r][c]

        // Start at lowest bit and shift it up
        allowance = 0x0010;
        bool keepLooking = true;
        for (i=0; (i<9) && keepLooking; i++)
        {
            if ((board[r][c] & allowance) != 0)
            {
                unsigned int newValue = (i+1);
                board[r][c] = (board[r][c] & (~VALUE_MASK)) | (newValue);
                board[r][c] = (board[r][c] & (~allowance));

                keepLooking = false;
            }
            // shift up for next digit
            allowance <<= 1;
        }

        // If no such digit exists
        if (keepLooking)
        {
            board[r][c] &= (~FILLED_MASK);  // position not filled in // 0x2000
            stack.pop();                    // pop the stack

            if (stack.isEmpty())
            {
                cout << "No solution." << endl;
                system("pause");
                return;
            }
            continue;
        }
        // Find best empty cell and place on stack
        bestEmpty = find_best_cell(board);
        // If no such cell exists then puzzle is solved
        if (!bestEmpty)
        {
            break;
        }
    }

    print_board(board);
}


int main()
{
    read_board(board);

    find_all_allowed_digits(board);

    solve_board(board);
}
