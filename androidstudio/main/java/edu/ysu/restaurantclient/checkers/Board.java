package edu.ysu.restaurantclient.checkers;
import android.graphics.Color;
import android.os.Build;
import android.widget.TextView;

import androidx.annotation.RequiresApi;

import java.util.Stack;
import java.util.Vector;

import edu.ysu.restaurantclient.R;

public class Board {
    Square[][] board;
    Piece red_1, red_2, red_3, red_4, red_5, red_6, red_7, red_8, red_9, red_10, red_11, red_12;
    Piece black_1, black_2, black_3, black_4, black_5, black_6, black_7, black_8, black_9, black_10, black_11, black_12;
    Vector<Piece> redPieces = new Vector<Piece>();
    Vector<Piece> blackPieces = new Vector<Piece>();
    public int redCounter = 12;
    public int blackCounter = 12;

    public Board(){
        
        board = new Square[8][8];
        /*
        redPieces.add(red_1 = new Piece()); blackPieces.add(black_1 = new Piece()); // Will be assigned to cells in the board array
        redPieces.add(red_2 = new Piece()); blackPieces.add(black_2 = new Piece());
        redPieces.add(red_3 = new Piece()); blackPieces.add(black_3 = new Piece());
        redPieces.add(red_4 = new Piece()); blackPieces.add(black_4 = new Piece());
        redPieces.add(red_5 = new Piece()); blackPieces.add(black_5 = new Piece());
        redPieces.add(red_6 = new Piece()); blackPieces.add(black_6 = new Piece());
        redPieces.add(red_7 = new Piece()); blackPieces.add(black_7 = new Piece());
        redPieces.add(red_8 = new Piece()); blackPieces.add(black_8 = new Piece());
        redPieces.add(red_9 = new Piece()); blackPieces.add(black_9 = new Piece());
        redPieces.add(red_10 = new Piece()); blackPieces.add(black_10 = new Piece());
        redPieces.add(red_11 = new Piece()); blackPieces.add(black_11 = new Piece());
        redPieces.add(red_12 = new Piece()); blackPieces.add(black_12 = new Piece());
        */
        this.fillPieces();
    }

    public void fillPieces(){
        redPieces.add(red_1 = new Piece()); blackPieces.add(black_1 = new Piece()); // Will be assigned to cells in the board array
        redPieces.add(red_2 = new Piece()); blackPieces.add(black_2 = new Piece());
        redPieces.add(red_3 = new Piece()); blackPieces.add(black_3 = new Piece());
        redPieces.add(red_4 = new Piece()); blackPieces.add(black_4 = new Piece());
        redPieces.add(red_5 = new Piece()); blackPieces.add(black_5 = new Piece());
        redPieces.add(red_6 = new Piece()); blackPieces.add(black_6 = new Piece());
        redPieces.add(red_7 = new Piece()); blackPieces.add(black_7 = new Piece());
        redPieces.add(red_8 = new Piece()); blackPieces.add(black_8 = new Piece());
        redPieces.add(red_9 = new Piece()); blackPieces.add(black_9 = new Piece());
        redPieces.add(red_10 = new Piece()); blackPieces.add(black_10 = new Piece());
        redPieces.add(red_11 = new Piece()); blackPieces.add(black_11 = new Piece());
        redPieces.add(red_12 = new Piece()); blackPieces.add(black_12 = new Piece());

        for (int i = 0; i < redPieces.size(); i++){
            redPieces.elementAt(i).setColor(Colour.red);
        }
        for (int i = 0; i < blackPieces.size(); i++){
            blackPieces.elementAt(i).setColor(Colour.black);
        }
    }

    public String getRedScore(){
        Integer returnString = 12 - (Integer)blackPieces.size();
        return "Red Score: " + returnString.toString();
    }

    public String getBlackScore(){
        Integer returnString = 12 - (Integer)redPieces.size();
        return "Black Score: " + returnString.toString();
    }

    public void placePieces (){
        int black = 0;
        int red = 0;
        for(int i = 0; i < 3; i++){
            for (int j = 0; j < 8; j++){
                if (board[i][j].getColor() == Color.rgb(0,0,0)){// is set to black
                    board[i][j].setOccupant(blackPieces.elementAt(black));
                    black++;
                }
            }
        }
        for(int i = 7; i > 4; i--){
            for (int j = 0; j < 8; j++){
                if (board[i][j].getColor() == Color.rgb(0,0,0)){// is set to black
                    board[i][j].setOccupant(redPieces.elementAt(red));
                    red++;
                }
            }
        }
    }

    public void setColors(){
        boolean reverse = false;
        for (int r = 0; r < 8; r++){
            boolean dark = true;
            if (reverse){
                for (int c = 7; c >= 0; c--){
                    if (dark){
                        board[r][c].setBlack();
                    }else
                        board[r][c].setWhite();

                    dark = !dark;
                }
            }else {
                for (int c = 0; c < 8; c++){
                    if (dark){
                        board[r][c].setBlack();
                    }else
                        board[r][c].setWhite();

                    dark = !dark;
                }
            }
            reverse = !reverse;
        }
    }

    public boolean isInBounds(int x, int y){
        if(x >= 0 && x < 8 && y >= 0 && y < 8){
            return true;
        }
        return false;
    }

    public void setCoordinates(){
        for (int r = 0; r < 8 ; r++){
            for (int c = 0; c < 8 ; c++){
                this.board[r][c] = new Square();
                this.board[r][c].setRow(r);
                this.board[r][c].setColumn(c);
            }
        }
    }

    public Square findSquare(int x ,int y){
        if(isInBounds(x,y)){
            return board[x][y];
        }
        return null;
    }

    public void setAdjacent(){
        for (int r = 0; r < 8; r++){
            for (int c = 0; c < 8; c++){
                if (isInBounds(r + 1, c - 1))
                    board[r][c].setBOTTOM_LEFT(board[r + 1][c - 1]);
                if (isInBounds(r + 1,c + 1))
                    board[r][c].setBOTTOM_RIGHT(board[r + 1][c + 1]);
                if(isInBounds(r - 1,c + 1))
                    board[r][c].setTOP_RIGHT(board[r - 1][c + 1]);
                if(isInBounds(r - 1,c - 1))
                    board[r][c].setTOP_LEFT(board[r - 1][c - 1]);
            }
        }
    }

    public Vector<Square> getJumps(Square square){
        int row = square.getRow();
        int column = square.getColumn();
        Piece piece = square.getOccupant();
        Vector<Square> jumps = new Vector<Square>();
        Square TOP_LEFT = square.getTOP_LEFT();
        Square TOP_RIGHT = square.getTOP_RIGHT();
        Square BOTTOM_LEFT = square.getBOTTOM_LEFT();
        Square BOTTOM_RIGHT = square.getBOTTOM_RIGHT();
        if(square.isOccupied()){
            if((piece.getColor() == Colour.red || piece.isKing())){
                if(isInBounds(row - 1, column - 1) && TOP_LEFT.isOccupied() && TOP_LEFT.getOccupant().getColor() != piece.getColor()){ //there's an enemy in the top left
                    if (isInBounds(row - 2,column - 2) && !findSquare(row - 2, column - 2).isOccupied()){ // a jump can be made
                        jumps.add(TOP_LEFT.getTOP_LEFT());
                    }
                }
                if(isInBounds(row - 1, column + 1) && TOP_RIGHT.isOccupied() && TOP_RIGHT.getOccupant().getColor() != piece.getColor()){ //there's an enemy in the top right
                    if (isInBounds(row - 2,column + 2) && !findSquare(row - 2, column + 2).isOccupied()){ // a jump can be made
                        jumps.add(TOP_RIGHT.getTOP_RIGHT());
                    }
                }
            }

            if((piece.getColor() == Colour.black || piece.isKing())){
                if(isInBounds(row + 1, column - 1) && BOTTOM_LEFT.isOccupied() && BOTTOM_LEFT.getOccupant().getColor() != piece.getColor()){ //there's an enemy in the bottom left
                    if (isInBounds(row + 2,column - 2) && !findSquare(row + 2, column - 2).isOccupied()){ // a jump can be made
                        jumps.add(BOTTOM_LEFT.getBOTTOM_LEFT());
                    }
                }
                if(isInBounds(row + 1, column + 1) && BOTTOM_RIGHT.isOccupied() && BOTTOM_RIGHT.getOccupant().getColor() != piece.getColor()){ //there's an enemy in the top right
                    if (isInBounds(row + 2,column + 2) && !findSquare(row + 2, column + 2).isOccupied()){ // a jump can be made
                        jumps.add(BOTTOM_RIGHT.getBOTTOM_RIGHT());
                    }
                }
            }
        }

        return jumps;
    }

    public Vector<Square> getMoves(Square square){// Here we find the possible moves of a given piece and send the result to the move function
        int row = square.getRow();
        int column = square.getColumn();
        Piece piece = square.getOccupant();
        Square TOP_LEFT = square.getTOP_LEFT();
        Square TOP_RIGHT = square.getTOP_RIGHT();
        Square BOTTOM_LEFT = square.getBOTTOM_LEFT();
        Square BOTTOM_RIGHT = square.getBOTTOM_RIGHT();

        Vector<Square> moves = new Vector<Square>(getJumps(square));
        if(square.isOccupied()){
            if((piece.getColor() == Colour.black || piece.isKing())){
                if(isInBounds(row + 1,column - 1)){//if the space at top left is empty
                    if(!BOTTOM_LEFT.isOccupied())
                        moves.add(BOTTOM_LEFT);
                }
                if(isInBounds(row + 1,column + 1)){//if the space at top right is empty
                    if(!BOTTOM_RIGHT.isOccupied())
                        moves.add(BOTTOM_RIGHT);
                }
            }
            if((piece.getColor() == Colour.red || piece.isKing())){
                if(isInBounds(row - 1,column - 1)){//if the space at bottom left is empty
                    if(!TOP_LEFT.isOccupied() )
                        moves.add(TOP_LEFT);
                }
                if(isInBounds(row - 1,column + 1)){//if the space at bottom right is empty
                    if(!TOP_RIGHT.isOccupied())
                        moves.add(TOP_RIGHT);
                }
            }
        }
        return moves;
    }

    public void highlightMoves(Square square){
        if(square.isOccupied()){
            for (Square cell:getMoves(square)
            ) {
                cell.setGreen();
            }
        }
    }

    public void move(Square start, Square end){// end is the selected destination for a piece
        int startRow = start.getRow();
        int startCol = start.getColumn();
        int endRow = end.getRow();
        int endCol = end.getColumn();
        Piece movedPiece = start.getOccupant();

        if(getMoves(start).contains(end)){
            end.setOccupant(movedPiece);
            start.setOccupant(null);
            if (!movedPiece.isKing()){ //if a non king piece reaches the opposite end of the board
                if (movedPiece.getColor() == Colour.red && end.getRow() == 0){
                    movedPiece.setKing(true);
                } else if (movedPiece.getColor() == Colour.black  && end.getRow() == 7){
                    movedPiece.setKing(true);
                }
            }

            if(Math.abs(end.getRow() - start.getRow()) == 2){ //we moved 2 rows, we made a jump
                if(redPieces.contains(findSquare((endRow + startRow) / 2, (endCol + startCol) / 2).getOccupant())){
                    redPieces.remove(findSquare((endRow + startRow) / 2, (endCol + startCol) / 2).getOccupant());
                    redCounter--;
                    counterCheck(redCounter);
                }else if(blackPieces.contains(findSquare((endRow + startRow) / 2, (endCol + startCol) / 2).getOccupant())) {
                    blackPieces.remove(findSquare((endRow + startRow) / 2, (endCol + startCol) / 2).getOccupant());
                    blackCounter--;
                    counterCheck(blackCounter);
                }
                findSquare((endRow + startRow) / 2, (endCol + startCol) / 2).setOccupant(null);//take away the jumped piece

                if(!getJumps(end).isEmpty()){//if there is another jump available after making a jump
                    move(end, getJumps(end).firstElement());// make the jump
                }
            }
        }
    }

    public void counterCheck(int counter) {
        if(counter == 0) {
            // increment scoreboard
            // reset board
            //resetBoard();
            redCounter = 12;
            blackCounter = 12;
        }
    }

    public void resetBoard() {
        redPieces.removeAllElements();
        blackPieces.removeAllElements();
        //setCoordinates();
        //setAdjacent();
        this.setColors();
        this.fillPieces();
        this.placePieces();
    }

}

/*    0 1 2 3 4 5 6 7
  0  |x|_|x|_|x|_|x|_|
  1  |_|x|_|x|_|x|_|x|
  2  |x|_|x|_|x|_|x|_|
  3  |_|_|_|_|_|_|_|_|
  4  |_|_|_|_|_|_|_|_|
  5  |_|o|_|o|_|o|_|o|
  6  |o|_|o|_|o|_|o|_|
  7  |_|o|_|o|_|o|_|o|

 */