//Looping
#include <iostream>
using namespace std;

int main()
{
    //Define variables
    int num1;
    int num2;
    int numActive = 1;
    int numTotal = 1;
    int numAdd;
    bool ValueCheck = true;

    //Prompt user
    cout << "Enter number to be counted to: ";
    cin >> num1;
    cout << "Count by increment: ";
    cin >> num2;

    //Main loop
    while (ValueCheck == true){
        numAdd = numActive += num2;
        if (numAdd <= num1){
            numTotal += numAdd;
        }

        if (numActive <= num1){
            cout << "Result: " << numActive << endl;
            else{
                ValueCheck = false;
                cout << "Total of numbers counted: " << numTotal << endl;
            }
        }
        }
    }

    return 0;
}
