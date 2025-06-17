#include <iostream>

using namespace std;

double myFunction(double x, double y){
    return x + y;
}

int main()
{
    double x = 10;
    double y = 5;
    cout<< myFunction(x, y);
    return 0;
}
