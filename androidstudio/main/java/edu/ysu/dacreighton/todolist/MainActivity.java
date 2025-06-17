package edu.ysu.dacreighton.todolist;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.view.ContextMenu;
import android.view.MenuInflater;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;
import android.view.Menu;
import android.view.MenuItem;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    Button addButton;
    EditText textBox;
    ListView todoList;
    ArrayList<String> list;
    TodoAdapter todoAdapter;
    Intent intent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        intent = new Intent(this, SecondActivity.class);

        addButton = findViewById(R.id.addButton);
        textBox = findViewById(R.id.textBox);
        todoList = findViewById(R.id.todoListView);
        list = new ArrayList<>();
        todoAdapter = new TodoAdapter(list, this);
        todoList.setOnItemClickListener(listClick);
    }

    public void onClickAdd(View view) {
        String text = textBox.getText().toString();
        if(!text.equals("")) {
            list.add(text);
            todoList.setAdapter(todoAdapter);
            textBox.setText("");
        }
    }
/*
    public void onCheck(View view) {
        //int position = todoList.getSelectedItemPosition();
        todoAdapter.getItem(todoList.getSelectedItemPosition());
        //list.remove(position);
        todoAdapter.remove(position);
    }
*/
    private AdapterView.OnItemClickListener listClick = new AdapterView.OnItemClickListener() {
        public void onItemClick(AdapterView parent, View view, int position, long id) {
            String itemValue = (String)todoList.getItemAtPosition(position);
            intent.putExtra("ITEM_SELECTED", itemValue);
            startActivity(intent);
        }
    };
}