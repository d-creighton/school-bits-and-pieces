#include <iostream>

using namespace std;

// ** Need Board
// ** Need values for all places on board - 3 x 3 array
// ** Display Board
// ** Initialize board
// Values for each player - Char - X and O
// Rules = How do you win, what if no winner
// Do you want to play again ? - Outer Loop
// Whose turn is it?
// 88 User input
// Move validation

void initBoard();
void drawBoard();
bool isGameOver();
void getMove(int &, int &, int);
bool validMove(int, int);

const int MAX_ROWS = 3, MAX_COLS = 3, MAX_Players = 2;

char board[MAX_ROWS][MAX_COLS];
char Player[MAX_Players] = {'X', 'O'};
int currentPlayer;

int main()
{
    int rPOS = 0, cPOS = 0, currentPlayer = 0;
    initBoard();

    do
    {
        drawBoard();

        do
        {
            getMove(rPOS, cPOS, currentPlayer );
        } while (!validMove(rPOS, cPOS));

        board[rPOS - 1][cPOS - 1] = Player[currentPlayer];

        // Switch to other player
        currentPlayer++;

        if (currentPlayer >= MAX_Players)
            currentPlayer = 0;


    } while (!isGameOver());

    return 0;
}

void initBoard()
{
    for (int row = 0; row < MAX_ROWS; row++)
        for (int col = 0; col < MAX_COLS; col++)
            board[row][col] = ' ';
}

void drawBoard()
{
    for (int count = 0; count < ((MAX_COLS + 1) * 3); count++)
    {
        cout << "-";
    }

    cout << "-" << endl;

    for (int row = 0; row < MAX_ROWS; row++)
        {
            cout << "| ";

            for (int col = 0; col < MAX_COLS; col++)
            {
                cout << board[row][col] << " | ";
            }

            cout << endl;

            for (int count = 0; count < ((MAX_COLS + 1) * 3); count++)
            {
                cout << "-";
            }

            cout << "-" << endl;

        }
}

bool isGameOver()
{
    bool result = false;

    if (
        // Horizontal Boxes
        board[0][0] != ' ' && (board[0][0] == board[0][1] && board[0][1] == board[0][2]) ||
        board[1][0] != ' ' && (board[1][0] == board[1][1] && board[1][1] == board[1][2]) ||
        board[2][0] != ' ' && (board[2][0] == board[2][1] && board[2][1] == board[2][2]) ||

        // Verical Boxes
        board[0][0] != ' ' && (board[0][0] == board[1][0] && board[1][0] == board[2][0]) ||
        board[0][1] != ' ' && (board[0][1] == board[1][1] && board[1][1] == board[2][1]) ||
        board[0][2] != ' ' && (board[0][2] == board[1][2] && board[1][2] == board[2][2]) ||

        // Diagonal Boxes
        board[0][0] == board[1][1] && board[1][1] == board[2][1] ||
        board[0][2] == board[1][1] && board[1][1] == board[2][0]

        )

        {
            result = true;
        }


    return result;
}

void getMove(int &row, int &col, int currentPlayer)
{
    cout << "Player " << Player[currentPlayer] <<
            ". Pease enter the row and col of your move: ";
    cin >> row >> col;
}

bool validMove(int row, int col)
{
    bool result = true;

    if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ')
    {
        result = false;
        cout << "You entered an invalid move.\n";
    }

    return result;
}
