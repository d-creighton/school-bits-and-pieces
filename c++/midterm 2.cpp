#include <iostream>
using namespace std;
int main()
{

  char ara[10];
    int counter=0;
    cout<<"Enter 10 characters in an array\n";
    for ( int a=0; a<10; a++)
        cin>>ara[a];

    for(int i=0;  i<10;  i++)
    {
       for(int j=i+1; j<10;  j++)
     {
         if(ara[i] == ara[j])
               {
                  counter++;
                  cout<<ara[i]<<"\t"<<counter<<endl;
               }
     }
    }

  return 0;
}
