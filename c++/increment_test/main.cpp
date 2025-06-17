//Start on number 1
#include <iostream>
using namespace std;

int main()
{
    int num1;
    int num2;
    int numActive = 1;
    int numTotal = 1;
    int numAdd;
    bool ValueCheck = true;

    cout << "Enter number to be counted to: ";
    cin >> num1;
    cout << "Count by increment: ";
    cin >> num2;

    do{
        numAdd = numActive += num2;
        if (numAdd <= num1){
            numTotal += numAdd;
        }

        if (numActive <= num1){
            cout << "Result: " << numActive << endl;
        }

        if (numActive >= num1){
            ValueCheck = false;
            cout << "Total of numbers counted: " << numTotal << endl;
        }
    } while (ValueCheck == true);

    return 0;
}
