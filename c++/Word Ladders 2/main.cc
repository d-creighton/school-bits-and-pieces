#include <iostream>
#include <linearlist.h>
#include <fstream>
#include <string>


using namespace std;

// Linked List
/*class WordList
{
    public:
        int wordIndex;
        WordList *ladder;
        WordList *nextWord;
};*/


struct WordInfo
{
    string word;
    int nextWord;

    LinearList<int> adjacentWords;
};

// Use file "sgb-words"
ifstream sgbWords;

//string allWords[5757], *pAllWords;      // array to hold all words

WordInfo allWords[5757];

void read_file()
{
    // Open file
    sgbWords.open ("sgb-words.txt");
    string str;

    // Print file contents
    /*while (getline(sgbWords, str))
    {
        cout << str << "\n";
    }*/

    // Pointers to WordList and allWords
    //pAllWords = allWords;           // address of first byte

    /*string *pWordList;
    *pWordList = WordList;*/

    while (getline(sgbWords, str))
    {
        // put all words into array
        for (int i=0; i<5757; i++)
        {
            allWords[i].word = str;
        }
    }
}

void user_input()
{
    // Get user entered words
    string userWord1;
    string userWord2;
    bool found1 = false;
    bool found2 = false;
    string line;

    cout << "Enter the first word: " << endl;
    cin >> userWord1;
    cout << "Enter the second word: " << endl;
    cin >> userWord2;

    // Search file for user inputs
    while (getline (sgbWords, line) && !found1)
    {
        if (userWord1 == line)
        {
            found1 = true;
        }
    }
    if (!found1)
    {
        cout << "Word 1 not in file." << endl;
    }

    // Return to beginning of file
    sgbWords.clear();
    sgbWords.seekg(0, ios::beg);

    while (getline (sgbWords, line) && !found2)
    {
        if (userWord2 == line)
        {
            found2 = true;
        }
    }
    if (!found2)
    {
        cout << "Word 2 not in file." << endl;
    }
}

int main()
{
    read_file();

    user_input();

    // Close file
    sgbWords.close();

    system("pause");
    return 0;
}