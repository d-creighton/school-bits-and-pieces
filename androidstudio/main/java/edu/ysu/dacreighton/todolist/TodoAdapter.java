package edu.ysu.dacreighton.todolist;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.CheckBox;
import android.widget.TextView;

import java.util.ArrayList;

public class TodoAdapter extends BaseAdapter {
    private ArrayList todoList;
    private LayoutInflater inflater;

    public TodoAdapter(ArrayList todoList, Context context) {
        this.todoList = todoList;
        this.inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
    }

    @Override
    public int getCount() {
        return todoList.size();
    }

    @Override
    public Object getItem(int position) {
        return todoList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        View view = inflater.inflate(R.layout.itemchecklist, null);
        TextView todoText = view.findViewById(R.id.todoText);
        CheckBox checkBox = view.findViewById(R.id.checkBox);

        checkBox.setChecked(false);
        todoText.setText(todoList.get(position).toString());

        return view;
    }

    public void remove(int position) {
        todoList.remove(todoList.get(position));
    }
}
