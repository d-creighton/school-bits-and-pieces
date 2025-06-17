#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  int num1 = 1;



  srand (time(0));
  int range = 6 - 1 + 1;
  int k = 0;
  int array[4];
  int i;
  int random;
  for (i=0; i<4; i++)
  {
    random = (rand() % range) + 1;
    array[i] = random; k++;
  }

  for (i=0; i<4; i++)
  {
    cout << array[i] << ' ';
  }

  cout << &num1;

  return 0;
}
