package edu.ysu.dacreighton.todolist;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
        Intent secondIntent = getIntent();
        String message = "Selected item is " + secondIntent.getStringExtra("ITEM_SELECTED");
        TextView text = (TextView)findViewById(R.id.textView);
        text.setText(message);
    }
}