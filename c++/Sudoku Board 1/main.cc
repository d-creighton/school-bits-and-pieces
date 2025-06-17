#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

unsigned int board[9][9];
static unsigned int FILLED_MASK  = 0x2000;
static unsigned int VALUE_MASK   = 0x000F;
static unsigned int ALLOWED_MASK = 0x1FF0;

// Note: this function will clear the "allowed" and "filled" bit fields.
void read_board(unsigned int board[9][9])
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
				board[r][c] = ch - '0';  // convert to integer. no error checking for 1 <= ch <= 9
				board[r][c] |= FILLED_MASK;
			}
		}
	}
}

void find_allowed_digits(unsigned int board[9][9], int row, int col)
{
	int r;
	int c;
	int i;
	unsigned int value;
	unsigned int allowed_bit;

	int allowed[9] = {true, true, true, true, true, true, true, true, true};

	// first do the given row
	// cout << "row " << row << endl;
	for (c=0; c<9; c++)
	{
		if ((board[row][c] & FILLED_MASK) != 0)
		{
			value = board[row][c] & VALUE_MASK;
			allowed[value - 1] = false;
			// cout << row << ", " << c << " v=" << value << endl;
		}
	}

	// now for the given column
	// cout << "col " << col << endl;
	for (r=0; r<9; r++)
	{
		if ((board[r][col] & FILLED_MASK) != 0)
		{
			value = board[r][col] & VALUE_MASK;
			allowed[value - 1] = false;
			// cout << r << ", " << col << " v=" << value << endl;
		}
	}

	// now for the given 3x3
	// cout << "3x3 " << row << " " << col << endl;
	for (r=((row/3)*3); r<(((row/3)+1)*3); r++)
	{
		for (c=((col/3)*3); c<(((col/3)+1)*3); c++)
		{
			// cout << r << ", " << c << endl;
			if ((board[r][c] & FILLED_MASK) != 0)
			{
				value = board[r][c] & VALUE_MASK;
				allowed[value - 1] = false;
				// cout << r << ", " << c << " v=" << value << endl;
			}
		}
	}

	// Start with the lowest bit set and shift it up.
	allowed_bit = 0x0010;
	for (i=0; i<9; i++)
	{
		// cout << (i+1) << " " << allowed[i] << endl;
		if (allowed[i])
		{
			board[row][col] |= allowed_bit;
		}
		// shift up for the next digit
		allowed_bit <<= 1; 
	}
}

void find_all_allowed_digits(unsigned int board[9][9])
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

void print_board(unsigned int board[9][9])
{
	int r;
	int c;
	unsigned int value;
	unsigned int allowed;
	unsigned int filled;


	for (r=0; r<9; r++)
	{
		cout << setw(18) << "value:";
		for (c=0; c<9; c++)
		{
			value = board[r][c] & VALUE_MASK;

			if (value == 0)
			{
				cout << setw(18) << ".";
			}
			else
			{
				cout << setw(18) << value;
			}
		}
		cout << endl;
		cout << setw(18) << "allowed:";
		for (c=0; c<9; c++)
		{
			allowed = board[r][c] & ALLOWED_MASK;

			cout << setw(18) << bitset<16>(allowed >> 4);
			// cout << setw(18) << hex << allowed;
		}
		cout << endl;
		cout << setw(18) << "filled:";
		for (c=0; c<9; c++)
		{
			filled = board[r][c] & FILLED_MASK;
			if (filled != 0)
			{
				cout << setw(18) << "Yes";
			}
			else
			{
				cout << setw(18) << "No";
			}

		}
		cout << endl;
		cout << endl;
	}
	cout << endl;

	system("pause");
}

// 0xed = 11101101

int main()
{
	read_board(board);
	find_all_allowed_digits(board);
	print_board(board);
}


/*

when I copy/paste the following as "input"...

4.......1
.2.7..59.
.98.437..
..1.2..7.
..53.49..
.8..9.2..
..798.12.
.52..7.3.
8.......7

I get the following output...

4 . . . . . . . 1 
. 2 . 7 . . 5 9 . 
. 9 8 . 4 3 7 . . 
. . 1 . 2 . . 7 . 
. . 5 3 . 4 9 . . 
. 8 . . 9 . 2 . . 
. . 7 9 8 . 1 2 . 
. 5 2 . . 7 . 3 . 
8 . . . . . . . 7 



.........
47..9..36
8...4...1
...2.4...
.25...48.
1.3...2.7
21.....48
....7....
.9.3.2.7.

infinite loop


..423...9
3.....27.
6..9.....
..3....54
4...86.9.
..9....26
1..7.....
9.....41.
..634...5

no solution


1.......9
.5.8...6.
....9.8.4
43..81...
6...2...1
...65..43
5.6.3....
.7...8.3.
2.......7

no solution





6...4....
...5..3.1
1..97....
2.5.....4
7.9.54.13
4....627.
.....5149
...4..8.7
3..7.1...




*/