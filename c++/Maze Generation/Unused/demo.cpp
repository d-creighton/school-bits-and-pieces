#include <iostream>
#include "sampler.h"

using namespace std;

int main(int argc,char *argv[]) {
    int32_t
        nR,nC;

    if (argc != 3) {
        cout << "Usage: " << argv[0] << " numrows numcols" << endl;
        return 1;
    }

    nR = strtol(argv[1],nullptr,10);
    nC = strtol(argv[2],nullptr,10);

    Sampler
        sampler(nR);

    cout << nC << endl;
    for (int i=0;i<nR;i++) {
        uint32_t val = sampler.sample();
        std::cout << val << std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}