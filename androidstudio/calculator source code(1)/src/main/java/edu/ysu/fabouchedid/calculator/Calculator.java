package edu.ysu.fabouchedid.calculator;

public class Calculator {
    private static final String INITIAL_VALUE = "0";

    private String input;
    private String previousInput;
    private Operator operator;
    private Boolean clearInput;

    public Calculator() {
        this.input = INITIAL_VALUE;
        this.previousInput = INITIAL_VALUE;
        this.clearInput = false;
    }

    public void inputNumber(Integer number) {
        if (clearInput) {
            previousInput = input;
            input = number.toString();
            clearInput = false;
        } else if (input.equals(INITIAL_VALUE)) {
            input = number.toString();
        } else {
            input += number.toString();
        }
    }

    public void inputOperator(Operator operator) {
        if (this.operator != null) {
            this.calculateTotal();
        }
        this.operator = operator;
        this.clearInput = true;
    }

    private void calculateTotal() {
        Double valueOne = Double.parseDouble(previousInput);
        Double valueTwo = Double.parseDouble(input);
        Double total = valueOne + valueTwo;
        //Do the math based on the operator
        //Switch statement
        input = total.toString();
    }

    public String getInput() {
        return this.input;
    }
}
