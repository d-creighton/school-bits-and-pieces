#include <iostream>
#include <bitset>
#include "sampler.h"
#include "DisjointSet.h"
#include "stack.h"
#include "pathfinder.h"

using namespace std;

// The stack
Stack<uint8_t> stack;

// Walls in cells that already had walls removed
bool WallsAbsent(int nR, int nC, uint8_t maze[MAX_ROWS][MAX_COLS], int r, int c, int d)
{
    uint8_t walls = maze[r][c];
    uint8_t wall = 0x01 << d;       // get bit mask for specific wall
    bool wallAbsent = ((walls & wall) == 0);

    if (wallAbsent)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Walls on outside edges
bool WallsExterior(int r, int c, int d, int nR, int nC)
{
    // Top edge
    if (r==0 && d==0)
    {
        return true;
    }
    // Bottom edge
    else if (r==(nR-1) && d==2)
    {
        return true;
    }
    // Left edge
    else if (c==0 && d==3)
    {
        return true;
    }
    // Right edge
    else if (c==(nC-1) && d==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void GenerateMaze(int numRow, int numCol, uint8_t maze[MAX_ROWS][MAX_COLS])
{
    int nR = numRow;
    int nC = numCol;
    int e;      // for smapler
    int d;      // direction
    int r;      // row
    int c;      // column
    // current cell and adjacent cell
    int cell1;
    int cell2;
    // current row and column
    int currentR;
    int currentC;
    // adjacent row and column
    int aR;
    int aC;

    int cell2dir;

    int i=0;

    for (int r=0; r<nR; r++)
    {
        for (int c=0; c<nC; c++)
        {
            maze[r][c] = 15;
        }
    }
    
    DisjointSet ds(nR*nC);
    Sampler sampler(4*nR*nC);

    i=0;

    while (i<(nR*nC-1))
    {
        do {
            do {
                e = sampler.sample();
                d = e % 4;
                c = ((e - d)/4) % nC;
                r = (((e - d)/4) - c)/nC;
            }
            while (WallsAbsent(nR, nC, maze, r, c, d) || WallsExterior(r, c, d, nR, nC));
            // (r,c) = (r*nC + c)
            currentR = r;
            currentC = c;
            cell1 = (currentR*nC + currentC);
            
            aR = r;
            aC = c;
            switch (d)
            {
                case 0:     // adjacent cell is up
                    aR--;
                    cell2 = (aR*nC + aC);
                    cell2dir = 2;
                    break;
                case 1:     // adjacent cell is right
                    aC++;
                    cell2 = (aR*nC + aC);
                    cell2dir = 3;
                    break;
                case 2:     // adjacent cell is down
                    aR++;
                    cell2 = (aR*nC + aC);
                    cell2dir = 0;
                    break;
                case 3:     // adjacent cell is left
                    aC--;
                    cell2 = (aR*nC + aC);
                    cell2dir = 1;
                    break;
            }
        }
        while (ds.find(cell1) == ds.find(cell2));

        ds.join(cell1, cell2);
        
        i++;

        // Remove BOTH walls
        // visit two cells of the maze matrix and clear a single bit from each
        uint8_t firstWall = 0x01 << d;
        maze[r][c] &= (~firstWall);
        uint8_t secondWall = 0x01 << cell2dir;
        maze[aR][aC] &= (~secondWall);
    }
}

void FindPath(int numRow, int numCol, uint8_t maze[MAX_ROWS][MAX_COLS])
{
    int nR = numRow;
    int nC = numCol;
    int r;
    int c;
    int d;
    int aR;
    int aC;

    // push (0,0,0) to stack as (r,c,d)
    // encode(r,c,d)
    /*
        cell = (r*nC + c)
        e = cell*5

        e=0 because (0*nC+0)*5 = 0
    */
    stack.push(0);
    
    // mark (0,0) as visited
    const uint8_t visited = 0x10;
    maze[0][0] &= (~visited);
    maze[0][0] |= visited;

    while (true)
    {
        // (r,c,d) = stack.peek();
        int e = stack.peek();
        d = e % 5;
        c = ((e - d)/5) % nC;
        r = (((e - d)/5) - c)/nC;
        
        if ((r == nR-1) && (c == nC-1))
        {
            break;
        }
        
        if (d==4)
        {
            // mark (r,c) as a dead end
            uint8_t deadEnd = 0x20;
            maze[r][c] &= (~deadEnd);
            maze[r][c] |= deadEnd;
            stack.pop();
        }
        else
        {
            aR = r;
            aC = c;
            // (aR, aC) is next cell in direction d
            switch (d)
            {
                case 0:     // adjacent cell is up
                    aR--;
                    break;
                case 1:     // adjacent cell is right
                    aC++;
                    break;
                case 2:     // adjacent cell is down
                    aR++;
                    break;
                case 3:     // adjacent cell is left
                    aC--;
                    break;
            }

            // push (r,c,d+1) to stack
            // e = d + 5(c+nC*r)
            e = (d+1) + (5*(c+nC*r));
            stack.pop();
            stack.push(e);

            if ((d<4) && (WallsAbsent(nR, nC, maze, r, c, d)) && ((maze[aR][aC] & visited) == 0))
            {
                // push (aR,aC,0) to stack
                e = 0 + (5*(aC+nC*aR));
                stack.push(e);
                
                // mark (aR,aC) as visited
                maze[aR][aC] &= (~visited);
                maze[aR][aC] |= visited;
            }
            
        }
    }
}
/*
    Function used for internal testing
void PrintMaze(int nR, int nC, uint8_t maze[MAX_ROWS][MAX_COLS])
{
    // ###
    // # #
    // ###

    for (int r=0; r<nR; r++)
    {
        string line1 = "";
        string line2 = "";
        string line3 = "";
        for (int c=0; c<nC; c++)
        {
            if ((maze[r][c] & 0x01) != 0)
            {
                line1 += "###";
            }
            else
            {
                line1 += "# #";
            }
            if((maze[r][c] & 0x08) != 0)
            {
                line2 += "# ";
            }
            else
            {
                line2 += "  ";
            }
            if ((maze[r][c] & 0x02) != 0)
            {
                line2 += "#";
            }
            else
            {
                line2 += " ";
            }
            if ((maze[r][c] & 0x04) != 0)
            {
                line3 += "###";
            }
            else
            {
                line3 += "# #";
            }
        }
        cout << line1 << endl;
        cout << line2 << endl;
        cout << line3 << endl;
    }
}
*/
// User input from argc and argv
int main(int argc, char *argv[])
{
    // Number of row and columns
    int32_t nR, nC;

    nR = strtol(argv[1],nullptr,10);
    nC = strtol(argv[2],nullptr,10);

    uint8_t maze[MAX_ROWS][MAX_COLS];

    GenerateMaze(nR, nC, maze);

    

    //PrintMaze(nR, nC, maze);

    printMaze(maze, nR, nC);
    FindPath(nR, nC, maze);
    return 0;
}