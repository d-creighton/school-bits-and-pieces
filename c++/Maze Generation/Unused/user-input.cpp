#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int32_t nR, nC;

    nR = strtol(argv[1],nullptr,10);
    nC = strtol(argv[2],nullptr,10);

    cout << nC << ' ' << nR;

    return 0;
}