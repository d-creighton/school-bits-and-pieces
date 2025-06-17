#include <iostream>
#include <ctype.h>
using namespace std;

struct Calendar
{
    //Inputed values
    string month_name;
    int rainfall,
        high_temp,
        low_temp;
    //Calculated values
    float monthly_avg_temp;
};

int main()
{
  struct Calendar month[12];
  int i;

  cout << "Rainfall:" << endl;
  cin >> month[i].rainfall;
  if(isalpha(month[i].rainfall))
  {
    cout << "alpha" << endl;
  }
  else
  {
    cout << month[i].rainfall;
  }


  return 0;
}
