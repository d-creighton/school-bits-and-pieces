#include <iostream>

using namespace std;

int main()
{
	char ch;
	int r;
	int c;

	int board[9][9];

	cout << "Enter the data: " << endl;
	
	cin >> ch;
	// read it
	for (r = 0; r < 9; r++)
	{
		for (c = 0; c < 9; c++)
		{
			
			//cin >> ch;
			if (ch == '.')
			{
				board[r][c] = 0;
			}
			else
			{
				board[r][c] = ch - '0';  // convert to integer. no error checking for 1 <= ch <= 9
			}
		}
	}

	// print it
	for (r = 0; r < 9; r++)
	{
		for (c = 0; c < 9; c++)
		{
			if (board[r][c] == 0)
			{
				cout << ". ";
			}
			else
			{
				cout << board[r][c] << " ";
			}
		}
		cout << endl;
	}
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


*/