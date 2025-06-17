#include <iostream>
#include <queue.h>
#include <linearlist.h>

using namespace std;

void print(char &ch) { cout << ch; }

int main(void) {
    string team = "Saskatchewan Squids";
    Queue<char> q;
    LinearList<char> list;
    int i;
    char c;

    for (i=0; i<team.length(); i++)
        // small s below
        if (team[i] == 's' || team[i] == 't' || team[i] == 'e')
            q.enqueue(team[i]);
        else
            list.insert(0,team[i]);

    while (!q.isEmpty()) {
        c = q.dequeue();
        cout << c;
    }

    list.map(print);

    cout << endl << "Done." << endl;

    return 0;
}