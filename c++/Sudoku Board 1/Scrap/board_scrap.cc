#include "board.h"
#include <cctype>
#include <iostream>
#include <string>


Board::Board(int nRows, int nCols, int board[][9], char input) {
	// 9 characters followed by return
	// repeat 9 times

	board[nRows][nCols];

	uint16_t cellValue;

	bool cellFilledIn;
	int currentChoice = cellValue & 0x000F; 		// currentChoice keeps lowest 4 digits in cellValue
	uint16_t whichDigitIsAllowed;

	

	// Reading input to fill in
	for (row = 0; row < nRows; row++)
	{
		for (col = 0; col < nCols; col++)
		{
			if (isdigit(input))				// check if input is digit
			{
				cellValue = input - '0';	// convert to int
				board[row][col] = cellValue;
				cellFilledIn = 1;
				whichDigitIsAllowed = 0;	// Start with 0, fill in later
				currentChoice = cellValue;
				FindAllowedDigits(candidates[9], board[][9], cellValue, cellFilledIn, currentChoice, whichDigitIsAllowed);		// will get back to candidates error after scrapping header
			}
			else
			{
				cellValue = 0;
				board[row][col] = cellValue;
				cellFilledIn = 0;
				whichDigitIsAllowed = 0;
				currentChoice = cellValue;
				FindAllowedDigits(candidates[9], board[][9], cellValue, cellFilledIn, currentChoice, whichDigitIsAllowed);		// will get back to candidates error after scrapping header			
			}
		}
	}
}
 
Board::~Board(void) { }

int Board::FindAllowedDigits(uint8_t candidates[], int board[][9], uint16_t cellValue, bool cellFilledIn, int currentChoice, uint16_t whichDigitIsAllowed) {
	// Allowances, 1 when allowed 0 when not
	bool allow1 = ((cellValue & 0x0010) !=0);		// True when not zero
	bool allow2 = ((cellValue & 0x0020) !=0);
	bool allow3 = ((cellValue & 0x0030) !=0);
	bool allow4 = ((cellValue & 0x0040) !=0);
	bool allow5 = ((cellValue & 0x0100) !=0);
	bool allow6 = ((cellValue & 0x0200) !=0);
	bool allow7 = ((cellValue & 0x0300) !=0);
	bool allow8 = ((cellValue & 0x0400) !=0);
	bool allow9 = ((cellValue & 0x1000) !=0);

	// Easy access to allowances
	int allowances[9] = {allow1, allow2, allow3, allow4, allow5, allow6, allow7, allow8, allow9};


	// Check rows
	for (row = 0; row < nRows; row++)
	{
		for (col = 0; col < nCols; col++)
		{
			for (board[row][col])
			{
				if (cellFilledIn)
				{
					cellValue |= 0x2000;		// 0010 x000
					for (int i=0; i<9; i++)
					{
						if (board[row][col] == candidates[i])
						{
							// set bit to zero
							// 000"0 0000 0000" 0000
							//cellValue = (cellValue & ~(cellValue << (i+5))) | (0 << (i+5));		// set (i+5)th bit to 0
																									// if i=0 then number is 1 so it must start at 5th bit from end
							allowances[i] = false;
						}
					}
				}
			}
		}
	}

	// Check columns
	for (col = 0; col < nCols; col++)
	{
		for (row = 0; row < nRows; row++)
		{
			for (board[row][col])
			{
				if (cellFilledIn)
				{
					cellValue |= 0x2000;		// 0010 x000
					for (int i=0; i<9; i++)
					{
						if (board[row][col] == candidates[i])
						{
							// set bit to zero
							// 000"0 0000 0000" 0000
							//cellValue = (cellValue & ~(cellValue << (i+5))) | (0 << (i+5));		// set (i+5)th bit to 0
																							// if i=0 then number is 1 so it must start at 5th bit from end
							allowances[i] = false;
						}
					}
				}
			}
		}
	}

	// 3x3 squares
	row=0;
	col=0;
	uint8_t rowGroup = int(row / 3);	// set row and col to zero beforehand?
	uint8_t colGroup = int(col / 3);	// nRows and nCols instead of row and col?
	int r, c;

	for (r = rowGroup * 3; r < (rowGroup + 1) * 3; r++)
	{
		for (c = colGroup * 3; c < (colGroup + 1) * 3; c++)
		{
			for (board[row][col])
			{
				if (cellFilledIn)
				{
					cellValue |= 0x2000;		// 0010 x000
					for (int i=0; i<9; i++)
					{
						if (board[row][col] == candidates[i])
						{
							// set bit to zero
							// 000"0 0000 0000" 0000
							//cellValue = (cellValue & ~(cellValue << (i+5))) | (0 << (i+5));		// set (i+5)th bit to 0
																							// if i=0 then number is 1 so it must start at 5th bit from end
							allowances[i] = false;
						}
					}
				}
			}
		}
	}

	// Put remaining candidates into whichDigitIsAllowed
	for (int i=0; i<9; i++)
	{
		if (allowances[i])
		{
			// Toggle (i+1)th bit of whichDigitIsAllowed
			whichDigitIsAllowed = (whichDigitIsAllowed ^ (1 << (i+1)));		// i could be 0 so +1 for first bit position
		}
	}
}

// Getters
int Board::numRows() const { return nRows; }
int Board::numCols() const { return nCols; }
int Board::getRow() { return row; }
int Board::getCol() { return col; }
uint8_t Board::getCand() { return candidates[9]; }

// I/O streams
std::istream& operator>>(std::istream& is, Board& b) {
	// Nine 9 digit lines
	// Either an int or a char(period)
	char input;			// input as char, converts to int if digit later

	is >> input;

	b = Board(input);

	return is;
}

std::ostream& operator<<(std::ostream& os, Board b) {

	return os;
}