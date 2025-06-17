#include "board.h"
#include <cctype>
#include <iostream>
#include <string>


Board::Board(int nRows, int nCols, int board[][9], char input) {
	// 9 characters followed by return
	// repeat 9 times

	/*
	The next line is not meaningful. 
	The only reason the compiler doesn't complain is that it thinks it knows what to do.
	I'm not going to tell you what the compiler thinks, I'm going to tell you what I think you mean or why I think 
	you're confused. I don't have the header file so I'm guessing a bit.

	You pass in arguments and here are some comments
	1. Please use an unsigned type for the calls of the board (like below, but not like the board argument)
	2. It is VERY ODD that you would pass in that matrix -- isn't it the job of this class to "own" the board -- who is sending this matrix and where did they get it?
	3. Why are you sending in one character? A board is read in as 9x9 characters

	In short, I would expect the class board to have a private member variable like this:
	uint16_t cells[9][9]

	I would expect it is the job of the constructor to read all the characters and populate this 9x9 matrix

	*/
	board[nRows][nCols];

	/*
	you have not initialized this value, but you use it below like it is.
	I think you expect this value to somehow be "remembered". 
	There is no attempt to presist this value. 
	*/
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
				/*
				What you're doing here is saying that the input argument "board" is the true storage for the board
				In other words, who ever pass that matrix is the true board and this class isn't.
				*/
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

	/*
	Lots to say here.
	I assume this is the intended layout of bit field:

	|....|....|....|....|
	|    |    |    |xxxx| -- the current choice
	|   x|xxxx|xxxx|    | -- digits allowed bit fields
	|  x |    |    |    | -- is filled in

	Let's look at your masks below. I'm going to write them in binary so you can see the mistake

	0x0010 -> |0000|0000|0001|0000|
	0x0020 -> |0000|0000|0010|0000|
	0x0030 -> |0000|0000|0011|0000|
	0x0040 -> |0000|0000|0100|0000|

	I'll stop there. Now look at 0x0030. That has two bits set. That implies two digits in this case.

	Here are the bit fields you want...

	|0000|0000|0001|0000| = 0x0010
	|0000|0000|0010|0000| = 0x0020
	|0000|0000|0100|0000| = 0x0040
	|0000|0000|1000|0000| = 0x0080
	|0000|0001|0000|0000| = 0x0100
	|0000|0010|0000|0000| = 0x0200
	|0000|0100|0000|0000| = 0x0400
	|0000|1000|0000|0000| = 0x0800
	|0001|0000|0000|0000| = 0x1000

	Notice that the hex number doubles with every row. That's because left shift is like multiplying by two.

	You are right about TRUE and FALSE. Make sure to use this logic:

	FALSE == 0 and TRUE != 0

	DO NOT TEST for TRUE == 1, since 0xFFFF is also TRUE

	*/
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
			/*
			What is your goal with this for loop? 
			It is not currently legal syntax since you need three values inside the parens for a "for" loop
			*/
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