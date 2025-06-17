
package edu.ysu.restaurantclient.checkers;

import androidx.annotation.RequiresApi;
import androidx.annotation.StringRes;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.drawable.Drawable;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import edu.ysu.restaurantclient.R;

public class CheckersActivity extends AppCompatActivity {
    public TextView[][] textView;
    public Board checkerBoard;
    public boolean redTurn = true;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_checkers);
        checkerBoard = new Board();
        checkerBoard.setCoordinates();
        checkerBoard.setAdjacent();
        checkerBoard.setColors();
        checkerBoard.placePieces();
        getSupportActionBar().setTitle("Checkers");
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);
        boolean redTurn = true;
        setTextView();
        draw(checkerBoard);
        setListeners(checkerBoard);
        Toast toast = Toast.makeText(getApplicationContext(), "Game Over", Toast.LENGTH_SHORT);


    }


    public void setListeners(Board board){
        boolean breakNow = false;
        if(checkerBoard.blackPieces.size() == 0){
            breakNow = true;
            Toast toast = Toast.makeText(getApplicationContext(),"Red Wins!", Toast.LENGTH_SHORT);
            toast.show();
        }else if(checkerBoard.redPieces.size() == 0) {
            breakNow = true;
            Toast toast = Toast.makeText(getApplicationContext(), "Black Wins!", Toast.LENGTH_SHORT);
            toast.show();
        }

        if(!breakNow){
            for(int i = 0; i < 8; i++){
                for (int j = 0; j < 8; j++ ){
                    TextView thisView = textView[i][j];
                    Square cell = board.board[i][j];
                    thisView.setOnClickListener(view -> {
                        if(cell.isOccupied()) {
                            if(redTurn && cell.getOccupant().getColor() == Colour.red){
                                board.highlightMoves(cell);
                                for(Square move: board.getMoves(cell)){
                                    int moveRow = move.getRow();
                                    int moveColumn = move.getColumn();
                                    textView[moveRow][moveColumn].setOnClickListener(moveView -> {
                                        board.move(cell,board.findSquare(moveRow,moveColumn));
                                        board.setColors();
                                        draw(board);
                                        redTurn = !redTurn;
                                        //board.resetBoard();
                                        setListeners(board);
                                    });
                                }
                            }else if((!redTurn) && cell.getOccupant().getColor() == Colour.black){
                                board.highlightMoves(cell);for(Square move: board.getMoves(cell)){
                                    int moveRow = move.getRow();
                                    int moveColumn = move.getColumn();
                                    textView[moveRow][moveColumn].setOnClickListener(moveView -> {
                                        board.move(cell,board.findSquare(moveRow,moveColumn));
                                        board.setColors();
                                        redTurn = !redTurn;
                                        draw(checkerBoard);
                                        setListeners(board);
                                    });
                                }
                            }
                        }
                        draw(checkerBoard);
                    });
                }
            }
        }else
            return;

    }

    public void setTextView(){
        textView = new TextView[8][8];
        textView[0][0] = findViewById(R.id.textView0_0);
        textView[0][1] = findViewById(R.id.textView0_1);
        textView[0][2] = findViewById(R.id.textView0_2);
        textView[0][3] = findViewById(R.id.textView0_3);
        textView[0][4] = findViewById(R.id.textView0_4);
        textView[0][5] = findViewById(R.id.textView0_5);
        textView[0][6] = findViewById(R.id.textView0_6);
        textView[0][7] = findViewById(R.id.textView0_7);

        textView[1][0] = findViewById(R.id.textView1_0);
        textView[1][1] = findViewById(R.id.textView1_1);
        textView[1][2] = findViewById(R.id.textView1_2);
        textView[1][3] = findViewById(R.id.textView1_3);
        textView[1][4] = findViewById(R.id.textView1_4);
        textView[1][5] = findViewById(R.id.textView1_5);
        textView[1][6] = findViewById(R.id.textView1_6);
        textView[1][7] = findViewById(R.id.textView1_7);

        textView[2][0] = findViewById(R.id.textView2_0);
        textView[2][1] = findViewById(R.id.textView2_1);
        textView[2][2] = findViewById(R.id.textView2_2);
        textView[2][3] = findViewById(R.id.textView2_3);
        textView[2][4] = findViewById(R.id.textView2_4);
        textView[2][5] = findViewById(R.id.textView2_5);
        textView[2][6] = findViewById(R.id.textView2_6);
        textView[2][7] = findViewById(R.id.textView2_7);

        textView[3][0] = findViewById(R.id.textView3_0);
        textView[3][1] = findViewById(R.id.textView3_1);
        textView[3][2] = findViewById(R.id.textView3_2);
        textView[3][3] = findViewById(R.id.textView3_3);
        textView[3][4] = findViewById(R.id.textView3_4);
        textView[3][5] = findViewById(R.id.textView3_5);
        textView[3][6] = findViewById(R.id.textView3_6);
        textView[3][7] = findViewById(R.id.textView3_7);

        textView[4][0] = findViewById(R.id.textView4_0);
        textView[4][1] = findViewById(R.id.textView4_1);
        textView[4][2] = findViewById(R.id.textView4_2);
        textView[4][3] = findViewById(R.id.textView4_3);
        textView[4][4] = findViewById(R.id.textView4_4);
        textView[4][5] = findViewById(R.id.textView4_5);
        textView[4][6] = findViewById(R.id.textView4_6);
        textView[4][7] = findViewById(R.id.textView4_7);

        textView[5][0] = findViewById(R.id.textView5_0);
        textView[5][1] = findViewById(R.id.textView5_1);
        textView[5][2] = findViewById(R.id.textView5_2);
        textView[5][3] = findViewById(R.id.textView5_3);
        textView[5][4] = findViewById(R.id.textView5_4);
        textView[5][5] = findViewById(R.id.textView5_5);
        textView[5][6] = findViewById(R.id.textView5_6);
        textView[5][7] = findViewById(R.id.textView5_7);

        textView[6][0] = findViewById(R.id.textView6_0);
        textView[6][1] = findViewById(R.id.textView6_1);
        textView[6][2] = findViewById(R.id.textView6_2);
        textView[6][3] = findViewById(R.id.textView6_3);
        textView[6][4] = findViewById(R.id.textView6_4);
        textView[6][5] = findViewById(R.id.textView6_5);
        textView[6][6] = findViewById(R.id.textView6_6);
        textView[6][7] = findViewById(R.id.textView6_7);

        textView[7][0] = findViewById(R.id.textView7_0);
        textView[7][1] = findViewById(R.id.textView7_1);
        textView[7][2] = findViewById(R.id.textView7_2);
        textView[7][3] = findViewById(R.id.textView7_3);
        textView[7][4] = findViewById(R.id.textView7_4);
        textView[7][5] = findViewById(R.id.textView7_5);
        textView[7][6] = findViewById(R.id.textView7_6);
        textView[7][7] = findViewById(R.id.textView7_7);
    }

    public void draw(Board checkerBoard){
        Square[][] boardColors = new Square[8][8];
        boardColors = checkerBoard.board;
        for(int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                Square cell = boardColors[i][j];
                if(!cell.isOccupied())
                    textView[i][j].setBackgroundColor(cell.getColor());
                else if(cell.isOccupied()){
                    if(cell.getOccupant().getColor() == Colour.red){
                        if (cell.getOccupant().isKing())
                            textView[i][j].setBackgroundResource(R.drawable.red_king);
                        else
                            textView[i][j].setBackgroundResource(R.drawable.red);
                    }else if(cell.getOccupant().getColor() == Colour.black){
                        if (cell.getOccupant().isKing())
                            textView[i][j].setBackgroundResource(R.drawable.blue_king);
                        else
                            textView[i][j].setBackgroundResource(R.drawable.blue);
                    }
                }
            }
        }
    }
}