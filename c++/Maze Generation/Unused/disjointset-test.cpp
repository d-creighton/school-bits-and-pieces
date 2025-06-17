#include <iostream>
#include "DisjointSet.h"

using namespace std;

int main(void)
{
    int nR = 3;
    int nC = 3;

    DisjointSet d(9);
    for (int r=0; r<3; r++)
    {
        for (int c=0; c<3; c++)
        {
            int a = r*3 + c;
            int f = d.find(a);
            cout << "r=" << r << " c=" << c << " set=" << f << endl;
        }
    }

    // I'm skipping a step. The value passed to find should be r*3+c.
    int a0 = d.find(0);
    int a1 = d.find(1);

    cout << "joining two sets: " << a0  << " and " << a1 << endl;

    d.join(a0, a1);

    for (int r=0; r<3; r++)
    {
        for (int c=0; c<3; c++)
        {
            int a = r*3 + c;
            int f = d.find(a);
            cout << "r=" << r << " c=" << c << " set=" << f << endl;
        }
    }

    // Now, let's join (0,2) with the set at (0,1)
    a0 = d.find(1);
    a1 = d.find(2);
    d.join(a0, a1);

    // Now, let's join (1,0), (1,1) and (1,2)
    a0 = d.find(3);
    a1 = d.find(4);
    d.join(a0, a1);

    a0 = d.find(3);
    a1 = d.find(5);
    d.join(a0, a1);

    // Now, let's join (2,0), (2,1) and (2,2)
    a0 = d.find(6);
    a1 = d.find(7);
    d.join(a0, a1);

    a0 = d.find(7);
    a1 = d.find(8);
    d.join(a0, a1);

    cout << "After joining all of row1, all of row2 and all of row3" << endl;

    for (int r=0; r<3; r++)
    {
        for (int c=0; c<3; c++)
        {
            int a = r*3 + c;
            int f = d.find(a);
            cout << "r=" << r << " c=" << c << " set=" << f << endl;
        }
    }

    /*
    // Sampling (picks walls at random)
    Sampler sampler(allWalls);
    for (int i=0; i<allWalls; i++)
    {
        uint32_t sampledValue = sampler.sample();
        //cout << "sampled value: " << sampledValue << endl;

        // Get direction and row and column of set (e)
        int e = items[sampledValue];
        int d = e % 4;
        int c = ((e - d)/4) % nC;
        int r = (((e - d)/4) - c)/nC;
        //cout << "e,d,c,r: " << e << ' ' << d << ' ' << c << ' ' << r << endl;
    }
    */

    return 0;
}