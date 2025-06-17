package edu.ysu.dacreighton.calculator;

import android.os.Bundle;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {
    private final Calculator calculator;
    private EditText display;

    public MainActivity() {
        super();
        calculator = new Calculator();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        display = this.findViewById(R.id.display);

        this.findViewById(R.id.zeroButton).setOnClickListener(view -> {
            handleInput(0);
        });

        this.findViewById(R.id.oneButton).setOnClickListener(view -> {
            handleInput(1);
        });

        this.findViewById(R.id.twoButton).setOnClickListener(view -> {
            handleInput(2);
        });

        this.findViewById(R.id.threeButton).setOnClickListener(view -> {
            handleInput(3);
        });

        this.findViewById(R.id.fourButton).setOnClickListener(view -> {
            handleInput(4);
        });

        this.findViewById(R.id.fiveButton).setOnClickListener(view -> {
            handleInput(5);
        });

        this.findViewById(R.id.sixButton).setOnClickListener(view -> {
            handleInput(6);
        });
        this.findViewById(R.id.sevenButton).setOnClickListener(view -> {
            handleInput(7);
        });

        this.findViewById(R.id.eightButton).setOnClickListener(view -> {
            handleInput(8);
        });

        this.findViewById(R.id.nineButton).setOnClickListener(view -> {
            handleInput(9);
        });

        this.findViewById(R.id.additionButton).setOnClickListener(view -> {
            handleOperator(Operator.Add);
        });

        this.findViewById(R.id.subtractionButton).setOnClickListener(view -> {
            handleOperator(Operator.Subtract);
        });

        this.findViewById(R.id.multiplicationButton).setOnClickListener(view -> {
            handleOperator(Operator.Multiply);
        });

        this.findViewById(R.id.divisionButton).setOnClickListener(view -> {
            handleOperator(Operator.Divide);
        });

        this.findViewById(R.id.equalButton).setOnClickListener(view -> {
            handleOperator(Operator.Equal);
        });

        this.findViewById(R.id.decimalButton).setOnClickListener(view -> {
            handleDecimal(".");
        });

        this.findViewById(R.id.percentageButton).setOnClickListener(view -> {
            handlePercentage("%");
        });

        this.findViewById(R.id.positiveOrNegativeButton).setOnClickListener(view -> {
            handlePosNeg("+/-");
        });

        this.findViewById(R.id.acButton).setOnClickListener(view -> {
            handleClear("AC");
        });
    }

    private void handleInput(Integer number) {
        calculator.inputNumber(number);
        display.setText(calculator.getInput());
    }

    private void handleOperator(Operator operator) {
        calculator.inputOperator(operator);
        display.setText(calculator.getInput());
    }

    private void handleDecimal(String decimal) {
        calculator.inputDecimal(decimal);
        display.setText(calculator.getInput());
    }

    private void handlePercentage(String percentage) {
        calculator.inputPercentage();
        display.setText(calculator.getInput());
    }

    private void handlePosNeg(String posNeg) {
        calculator.inputPosNeg();
        display.setText(calculator.getInput());
    }

    private void handleClear(String clear) {
        calculator.inputClear();
        display.setText(calculator.getInput());
    }
}