#include <iostream>
#include <string>
#include <linearlist.h>

using namespace std;

string words[] = {
    "A",
    "B",
    "C",
    "D",
    "E"
};

int slots[] = {0,1,0,2,1};

void Print(string &s) {
    cout << s << ' ';
}

int main(void) {
    int i;
    LinearList<string> myList;

    for (i=0;i<5;i++)
        myList.insert(slots[i],words[i]);

    myList.map(Print);
    cout << "\nDone!\n";

    return 0;
}