#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//Show Menu
//string Menu()

//Inputing a string

bool isvowel(char c)
    {
        static vowels[]={'A','E','I','O','U'};
        for (i=0; i<5; i++)
        {
            if (c == vowels[i])
            {
                return true;
            }
        }
    }

int main()
{

    string str;
    int i=0;
    char c;

    cout << "Enter a string:\n";
    cin >> str;
    /*while (str[i])
    {
        c=str[i];
        putchar (toupper(c));
        i++;

    }*/





    return 0;
}
