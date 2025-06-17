#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

//Check if Vowel
bool isvowel(char letter)
{
    int i;
    static char vowels[] = {'A','E','I','O','U'};
    for (i=0; i<5; i++)
    {
        if (letter == vowels[i])
        {
            return true;
        }
        //return false;
    }
    return false;
}
//Vowel counting
int countvowels(char line[], const int size)
{
    int i = 0;
    char target;
    int count = 0;
    int rcount = 0;
    while (count < size)
    {
        target = *(line + count);
        if (isvowel(target))
        {
            rcount++;
        }

        count++;
    }
    return rcount;
}
//Consonant counting
int countcon(char line[], const int size)
{
    int i = 0;
    char target;
    int count = 0;
    int rcount = 0;
    while (count < size)
    {
        target = *(line + count);
        if (!isvowel(target))
        {
            if (isalpha(target))
            {
                rcount++;
            }
            else if (target == '\0')
            {
                return rcount;
            }
        }

        count++;
    }
    return rcount;
}
//Menu
char menu(char option, bool flag2)
{
    do
    {
        cout << "A) Display number of vowels\nB) Display number of consonants\nC) Display both\nD) Enter another string\nE) Exit\n" << endl;
        cout << "Please pick option A, B, C, D, or E." << endl;
        cin >> option;
        option = toupper(option);

        if (option == 'A')
        {
            flag2 = false;
            return option;
        }
        else if (option == 'B')
        {
            flag2 = false;
            return option;
        }
        else if (option == 'C')
        {
            flag2 = false;
            return option;
        }
        else if (option == 'D')
        {
            flag2 = false;
            return option;
        }
        else if (option == 'E')
        {
            flag2 = false;
            return option;
        }
        else
        {
            cout << "Please select one of the available options." << endl;
        }
    }
    while (flag2 == true);
    return 'E';
}

int main()
{
    //Variables
    const int size = 100;
    char line[size];
    char option;
    bool flag1 = true;
    bool flag2 = true;

    //User input first string
    while (flag1 == true)
    {
        cout << "Enter a string:\n";
        cin.getline(line, size);

        for (char *iter = line; *iter != '\0'; ++iter)
        {
            *iter = toupper(*iter);
        }

        //Pick menu option
        option = menu(option, flag2);
        //Option calling
        if (option == 'A')
        {
            cout << "There is/are " << countvowels(line, size) << " vowel(s).\n" << endl;
            continue;
        }
        else if (option == 'B')
        {
            cout << "There is/are " << countcon(line, size) << " consonant(s).\n" << endl;
            continue;
        }
        else if (option == 'C')
        {
            cout << "There is/are " << countvowels(line, size) << " vowel(s)." << endl;
            cout << "There is/are " << countcon(line, size) << " consonant(s).\n" << endl;
            continue;
        }
        else if (option == 'D')
        {
            cin.ignore();//allows reuse of getline
            continue;
        }
        else if (option == 'E')
        {
            flag1 = false;
        }
    }
    return 0;
}
