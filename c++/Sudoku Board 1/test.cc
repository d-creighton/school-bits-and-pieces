#include <iostream>
#include "stack.h"
//#include "queue.h"

using namespace std;

int main() {
  string
    str;
  Stack<char>
    s;
  /*Queue<char>
    q;*/

  cout << "Enter a line of text: ";
  //std::cin.getline(cin,str);
  cin >> str;

  for (int i=0;i<str.length();i++) {
    s.push(str[i]);
    //q.enqueue(str[i]);
  }

  cout << s.peek();

  cout << "This should be in reverse order:\n[";
  while (!s.isEmpty())
    cout << s.pop();
  cout << ']' << endl << endl;

  /*cout << "This should be a copy:\n[";
  while (!q.isEmpty())
    cout << q.dequeue();
  cout << ']' << endl;*/

  system("pause");
  return 0;
}

