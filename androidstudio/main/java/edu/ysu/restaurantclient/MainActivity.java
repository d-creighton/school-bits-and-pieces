package edu.ysu.restaurantclient;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;

import edu.ysu.restaurantclient.menu.MenuActivity;
import edu.ysu.restaurantclient.quiz.QuizFragment;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

       Button button = this.findViewById(R.id.triviaButton);
       button.setOnClickListener( (view) -> {
           Fragment fragment = QuizFragment.newInstance();
           getSupportFragmentManager().beginTransaction().add(R.id.fragment_quiz, fragment).commit();
       });

       Button menuButton = this.findViewById(R.id.menuButton);
       menuButton.setOnClickListener(v -> {
           Intent intent = new Intent(this, MenuActivity.class);
           startActivity(intent);
       });
    }
}
