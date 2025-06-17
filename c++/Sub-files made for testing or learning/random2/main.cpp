#include <iostream>

using namespace std;

int main()
{
    char line[80];
    cout << "Enter a string:\n";
    cin.getline(line, 80);
    cout << line << endl;
    return 0;
}
