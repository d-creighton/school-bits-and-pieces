package edu.ysu.restaurantclient.checkers;

import android.graphics.Color;
import android.widget.TextView;

public class Square {
    private Piece occupant; // implement piece class
    private boolean occupied;
    private int row;
    private int column;
    private Square TOP_LEFT;
    private Square TOP_RIGHT;
    private Square BOTTOM_LEFT;
    private Square BOTTOM_RIGHT;
    private int color;
    //private TextView textView = new TextView();

   public Square(){
        this.occupant = null;
        this.occupied = false;
       //textView = new TextView();
    }
/*
    public TextView getTextView() {
        return textView;
    }

    public void setTextView(TextView textView) {
        this.textView = textView;
    }
*/
    public int getColor(){
       return this.color;
    }
    public void setGreen(){
        this.color = Color.rgb(0,128,0);
    }

    public void setWhite(){
       this.color = Color.rgb(255,255,255);
        //this.textView.setBackgroundColor(this.color);
    }
    public void setBlack(){
       this.color = Color.rgb(0,0,0);
       //this.textView.setBackgroundColor(this.color);
    }

    public boolean isBorder(Square square){
       if (square.getRow() == 0 || square.getRow()==7 || square.getColumn() == 0 || square.getColumn() == 7 ){
           return true;
       }
       return false;
    }

    public int getRow() {
        return row;
    }

    public void setRow(int row) {
        this.row = row;
    }

    public int getColumn() {
        return column;
    }
    public void setColumn(int column) {
        this.column = column;
    }

    public boolean isOccupied() {
        return occupied;
    }
    public void setOccupied(boolean occupied) {
        this.occupied = occupied;
    }

    public Piece getOccupant() {
        return occupant;
    }
    public void setOccupant(Piece occupant) {
        this.occupant = occupant;
        this.setOccupied(!isOccupied()); //will switch occupied status to opposite of itself
    }

    public Square getTOP_LEFT() {
        return TOP_LEFT;
    }

    public void setTOP_LEFT(Square TOP_LEFT) {
        this.TOP_LEFT = TOP_LEFT;
    }

    public Square getTOP_RIGHT() {
        return TOP_RIGHT;
    }

    public void setTOP_RIGHT(Square TOP_RIGHT) {
        this.TOP_RIGHT = TOP_RIGHT;
    }

    public Square getBOTTOM_LEFT() {
        return BOTTOM_LEFT;
    }

    public void setBOTTOM_LEFT(Square BOTTOM_LEFT) {
        this.BOTTOM_LEFT = BOTTOM_LEFT;
    }

    public Square getBOTTOM_RIGHT() {
        return BOTTOM_RIGHT;
    }

    public void setBOTTOM_RIGHT(Square BOTTOM_RIGHT) {
        this.BOTTOM_RIGHT = BOTTOM_RIGHT;
    }
}
