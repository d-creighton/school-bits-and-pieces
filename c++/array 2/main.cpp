#include <iostream>

using namespace std;

int main()
{
    double prices[9] = {};
    for(int i=0;i<9;i++)
    {
        cout << "Please enter price:" << endl;
        cin >> prices[i];
    }

    for (int i = 0; i<9; i++)
    {
        cout << prices[i] << " ";
    }

    cout << "\n\n";
    for (int i = 0; i<9; i++)
    {
        cout << prices[i] << " ";
        if ((i % 3)==2)
        {
            cout << endl;
        }
    }
    return 0;
}
