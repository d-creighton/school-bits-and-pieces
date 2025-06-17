#include <iostream>
#include <cctype>
#include <string>

#ifndef _BOARD_H
#define _BOARD_H

class Board {
	// Constructor
public:
	Board(int nRows, int nCols, int board[][9], char input);
	// Deconstructor
	~Board(void);

	int FindAllowedDigits(uint8_t candidates[], int board[][9], uint16_t cellValue, bool cellFilledIn, int currentChoice, uint16_t whichDigitIsAllowed);

	// Getters
	int getRow();
	int getCol();
	uint8_t getCand();
	// Number of rows and columns
	int numRows() const;
	int numCols() const;

	// Row and column
private:
	int row, col;
	int nRows = 9, nCols = 9;

	uint8_t candidates[9] = { 1,2,3,4,5,6,7,8,9 };
};

// I/O
std::istream& operator>>(std::istream& is, Board& b);
std::ostream& operator<<(std::ostream& os, Board b);

#endif