#include <iostream>
#include <queue.h>
#include <linearlist.h>
#include <fstream>
#include <string>


using namespace std;

// Linked List
struct WordInfo
{
    string word;
    int nextWord;

    LinearList<int> adjacentWords;
};

// Use file "sgb-words"
ifstream sgbWords;

// Array to hold all words
WordInfo allWords[5757];

//Queue
Queue<int> Q;

// Word ladder list
LinearList<int> S;

void read_file()
{
    // Open file
    sgbWords.open ("sgb-words.txt"); 
    string line;

    // put all words into array
    for (int i=0; i<5757; i++)
    {
        sgbWords >> line;

        allWords[i].word = line;
        allWords[i].nextWord = -1;
    }
}

int HammingDistance(struct WordInfo *word1, struct WordInfo *word2)
{
    // Determining Hamming Distance
    int d = 0;
    for (int charIndex = 0; charIndex < 5; charIndex++)
    {
        // if character not the same, increase count
        if (word1->word[charIndex] != word2->word[charIndex])
        {
            d++;
        }
    }

    return d;
}

void AddAdjacentWord(struct WordInfo *word, int i)
{
    // add position of adjacent word to linear list
    word->adjacentWords.insert(0, i);
}

// Display Linear List
void displayLinearList(int &i)
{
    cout << allWords[i].word << endl;
}

void findHammingDistance()
{
    // Nested loop to go through each word pair in array
    for (int i=0; i<5756; i++)
    {
        for (int j=i+1; j<5757; j++)
        {
            int d = HammingDistance(&(allWords[i]), &(allWords[j]));
            if (d <= 1)
            {
                AddAdjacentWord(&(allWords[i]), j);
                AddAdjacentWord(&(allWords[j]), i);
            }
        }
    }
}

void generateWordLadder(int w1, int w2)
{
    int v;
    int w;
    // Clear list from w1 to w2
    // S is the word ladder
    S.clear();

    // Add w2 to queue Q
    Q.enqueue(w2);

    // while Q is not empty
    while (!Q.isEmpty())
    {
        // dequeue Q into w
        w = Q.dequeue();
        //cout << "w: " << w << endl;

        // for each word v in w.list do
        for (v=0; v<allWords[w].adjacentWords.size(); v++)
        {
            // if v.ptr = NULL and v != w2 then
            // v pointing to current adjacentWord's nextWord value
            int adjacent = allWords[w].adjacentWords[v];

            if ((allWords[adjacent].nextWord == -1) && (allWords[adjacent].word != allWords[w2].word))
            {
                // v.ptr = w
                // v pointing to current adjacentWord's nextWord value
                allWords[adjacent].nextWord = w;
                
                // enqueue v in Q
                Q.enqueue(adjacent);
            }
        }
    }

    // if w1.ptr != NULL then
    if (allWords[w1].nextWord != -1)
    {
        // append w1 to S
        S.insert(S.size(), w1);
        // w = w1.ptr
        w = allWords[w1].nextWord;

        // while w != NULL do
        while (w != -1)
        {
            // append w to S
            S.insert(S.size(), w);
            // w = w.ptr
            w = allWords[w].nextWord;
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
    int w1 = 0;
    int w2 = 0;

    cout << "Enter the first word: " << endl;
    cin >> userWord1;
    cout << "Enter the second word: " << endl;
    cin >> userWord2;

    // Search array for user inputs
    for (int i=0; i<5757; i++)
    {
        if (allWords[i].word == userWord1)
        {
            w1 = i;
            found1 = true;
        }
    }
    if (!found1)
    {
        cout << "Word 1 not in array." << endl;
    }

    for (int i=0; i<5757; i++)
    {
        if (allWords[i].word == userWord2)
        {
            w2 = i;
            found2 = true;
        }
    }
    if (!found2)
    {
        cout << "Word 2 not in array." << endl;
    }

    // If both user words in file, generate word ladder
    if (found1 && found2)
    {
        generateWordLadder(w1, w2);
    }

    if (S.isEmpty())
    {
        cout << "No ladder exists." << endl;
    }
    else
    {
        S.map(displayLinearList);
    }
    
}

int main()
{
    read_file();

    findHammingDistance();

    user_input();

    // Close file
    sgbWords.close();

    system("pause");
    return 0;
}