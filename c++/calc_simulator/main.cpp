#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    //Variables
    double dbl_X;
    double dbl_Y;
    string str_operation;
    bool marker;
    double Ans;

    //Prompt for first number
    cout << "Enter the first number:\n";
    cin >> dbl_X;

    //Prompt operation
    marker = 1;
    while (marker){
        cout << "Select operation, enter +, -, *, or /:\n"; //cannot be anything other than +,-,*,/
        cin >> str_operation;
        if (str_operation == "+"){
            marker = 0;
        }
        else if (str_operation == "-"){
            marker = 0;
        }
        else if (str_operation == "*"){
            marker = 0;
        }
        else if (str_operation == "/"){
            marker = 0;
        }
        else {
            cout << "Operation invalid.\n";
        }
    }

    //Prompt second number
    cout << "Enter the second number:\n";
    cin >> dbl_Y;

    //Perform operation
    if (str_operation == "+"){
        Ans = dbl_X + dbl_Y;
        cout << "Answer:\n" << Ans << endl;
    }
    else if (str_operation == "-"){
        Ans = dbl_X - dbl_Y;
        cout << "Answer:\n" << Ans << endl;
    }
    else if (str_operation == "*"){
        Ans = dbl_X * dbl_Y;
        cout << "Answer:\n" << Ans << endl;
    }
    else {
        Ans = dbl_X / dbl_Y;
        cout << "Answer:\n" << Ans << endl;
    }
    return 0;
}
