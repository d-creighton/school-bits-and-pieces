#include <iostream>
#include <new>

using namespace std;

int main()
{
    bool flag = true;
    bool mark = true;
    int i;
    int n;
    int * p;

    do {
        cout << "Enter the number of students surveyed:" << endl;
        cin >> i;
        p = new (nothrow) int[i];
        if (p == nullptr){
                cout << "Error: memory could not be allocated";
            }
        else if (i <= 0){
            cout << "Please enter a positive nonzero number." << endl;
        }
        else {
            //if (p == nullptr){
                //cout << "Error: memory could not be allocated";
            //}
            flag = false;
        }
    } while (flag == true);



    return 0;
}
