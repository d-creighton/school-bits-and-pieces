#ifndef DISJOINT_SET
#define DISJOINT_SET

#include <cstdint>

class DisjointSet
{
    public:
        DisjointSet(int n);
        ~DisjointSet();

        int find(int a);

        void join(int a, int b);

    private:
        int numEl;
        int *elements;
        int *rank;
};

#endif