#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

//Check if Vowel
/*bool isvowel(char c)
{
    int i = 0;
    c = toupper(c);
    //return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    static char vowels[] = {'A','E','I','O','U'};
    for (i=0; i<5; i++)
    {
        if (c == vowels[i])
        {
            return true;
        }
    }
}*/
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
        static char vowels[] = {'A','E','I','O','U'};
        for (i=0; i<5; i++)
        {
            if (target == vowels[i])
            {
                rcount++;
            }
        }
        count++;
    }
    return rcount;
}
//Consonant counting
/*int countcon(char line[], const int size)
{
    int i = 0;
    char target;
    int count = 0;
    //int rcount = 0;
    //char nullcheck = (line[count] != '\0');
    while (count < size)
    {
        int rcount = 0;

        target = *(line + count);
        //static char cons[] = {'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};
        static char vowels[] = {'A','E','I','O','U'};
        for (i=0; i<5; i++)
        {
            if (target == vowels[i])
            {
                //rcount++;
            }
            else
            {
                rcount++;
            }
        }
        count++;
        return rcount;
    }
    //return rcount;
}*/
int countcon(char line[], const int size)
{
    //int i = 0;
    char target;
    int rcount = 0;
    int count = 0;
    while (count < size)
    {
        target = *(line + count);
        if ((target >= 'A' && target <= 'Z'))
        {
            rcount++;
        }
    }
    return rcount;
}
//Menu
string menu(string option, bool flag2)
{
    do
    {
        cout << "A) Display number of vowels\nB) Display number of consonants\nC) Display both\nD) Enter another string\nE) Exit\n" << endl;
        cout << "Please pick option A, B, C, D, or E." << endl;
        cin >> option;
        if (option == "A")
        {
            flag2 = false;
            return option;
        }
        else if (option == "B")
        {
            flag2 = false;
            return option;
        }
        else if (option == "C")
        {
            flag2 = false;
            return option;
        }
        else if (option == "D")
        {
            flag2 = false;
            return option;
        }
        else if (option == "E")
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
}
int main()
{
    //Variables
    char line[80];
    //string str;
    string option;
    const int size = 80;
    bool flag1 = true;
    bool flag2 = true;
    //User input first string
    while (flag1 == true)
    {
        cout << "Enter a string:\n";
        cin.getline(line, 80);
        //Pick menu option
        option = menu(option, flag2);
        //Option calling
        if (option == "A")
        {
            cout << "There is/are " << countvowels(line, size) << " vowel(s).\n" << endl;
            continue;
        }
        else if (option == "B")
        {
            cout << "There is/are " << countcon(line, size) << " consonant(s).\n" << endl;
            continue;
        }
        else if (option == "C")
        {
            cout << "There is/are " << countvowels(line, size) << " vowel(s)." << endl;
            cout << "There is/are " << countcon(line, size) << " consonant(s).\n" << endl;
            continue;
        }
        else if (option == "D")
        {
            continue;
        }
        else if (option == "E")
        {
            flag1 = false;
        }
    }
    return 0;
}
