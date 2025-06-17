#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

bool isvowel(char target, char letter)
{
    int i = 0;
    letter = toupper(letter);
    //return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    static char vowels[] = {'A','E','I','O','U'};
    for (i=0; i<5; i++)
    {
        if (letter == vowels[i])
        {
            return true;
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
