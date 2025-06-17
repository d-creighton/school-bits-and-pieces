#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Pick operation
string showMenu(string str_operation, bool flag){
    do{
        cout << "Select operation, enter +, -, *, or /:\n";
        cin >> str_operation;
        if (str_operation == "+"){
            flag = false;
            return str_operation;
        }
        else if (str_operation == "-"){
            flag = false;
            return str_operation;
        }
        else if (str_operation == "*"){
            flag = false;
            return str_operation;
        }
        else if (str_operation == "/"){
            flag = false;
            return str_operation;
        }
        else {
            cout << "Operation invalid.\n";
        }
    } while (flag == true);
}

//Addition
double add(double dbl_X, double dbl_Y){
    return (dbl_X + dbl_Y);
}

//Subtraction
double subtract(double dbl_X, double dbl_Y){
    return (dbl_X - dbl_Y);
}

//Multiplication
double multiply(double dbl_X, double dbl_Y){
    return (dbl_X * dbl_Y);
}

//Division
double divide(double dbl_X, double dbl_Y){
    return (dbl_X / dbl_Y);
}

int main()
{
    //Variables
    double dbl_X;
    double dbl_Y;
    string str_operation;
    bool flag = true;

    //Prompt for first number
    cout << "Enter the first number:\n";
    cin >> dbl_X;

    //Assign operation
    str_operation = showMenu(str_operation, flag);

    //Prompt for second number
    cout << "Enter the second number:\n";
    cin >> dbl_Y;

    //Calculations
    if (str_operation == "+"){
        cout << "Answer:\n" << add(dbl_X, dbl_Y);
    }
    else if (str_operation == "-"){
        cout << "Answer:\n" << subtract(dbl_X, dbl_Y);
    }
    else if (str_operation == "*"){
        cout << "Answer:\n" << multiply(dbl_X, dbl_Y);
    }
    else if (str_operation == "/"){
        cout << "Answer:\n" << divide(dbl_X, dbl_Y);
    }


    return 0;
}
