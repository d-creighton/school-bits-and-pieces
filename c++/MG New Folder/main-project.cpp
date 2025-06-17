#include <iostream>
#include <bitset>
#include "sampler.h"
#include "DisjointSet.h"
#include "stack.h"

using namespace std;

// The stack
Stack<uint8_t> stack;

// Walls in cells that already had walls removed
bool WallsAbsent(int nR, int nC, uint8_t **maze, int r, int c, int d)
{
    //cout << "WallsAbsent: masking" << endl;
    uint8_t walls = maze[r][c];
    uint8_t wall = 0x01 << d;       // get bit mask for specific wall
    bool wallAbsent = ((walls & wall) == 0);
    cout << "wallAbsent=" << wallAbsent << endl;
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
    //cout << "WallsExterior: finding wall" << endl;
    // Top edge
    if (r==0 && d==0)
    {
        cout << "Top edge" << endl;
        return true;
    }
    // Bottom edge
    else if (r==(nR-1) && d==2)
    {
        cout << "Bottom edge" << endl;
        return true;
    }
    // Left edge
    else if (c==0 && d==3)
    {
        cout << "Left edge" << endl;
        return true;
    }
    // Right edge
    else if (c==(nC-1) && d==1)
    {
        cout << "Right edge" << endl;
        return true;
    }
    else
    {
        cout << "WallsExterior=false" << endl;
        return false;
    }
}
/*
void GetAdjacentCell(int row, int col, int dir, int cell2, int nC, int* adjacentRow, int* adjacnetCol)
{
    int adjacentRow = row;
    int adjacentCol = col;
    switch (dir)
    {
        case 0:     // adjacent cell is up
            adjacentRow++;
            cell2 = (adjacentRow*nC + adjacentCol);
            break;
        case 1:     // adjacent cell is right
            adjacnetCol++;
            cell2 = (adjacentRow*nC + adjacentCol);
            break;
        case 2:     // adjacent cell is down
            adjacentRow--;
            cell2 = (adjacentRow*nC + adjacentCol);
            break;
        case 3:     // adjacent cell is left
            adjacnetCol--;
            cell2 = (adjacentRow*nC + adjacentCol);
            break;
    }
}
*/
void GenerateMaze(int numRow, int numCol, uint8_t **maze)
{
    // Maze array size depends on user inputs
    int nR = numRow;
    int nC = numCol;
    /*cout << "Building maze["<<nR<<"]["<<nC<<"]"<<endl;
    uint8_t **maze;
    maze = new uint8_t*[nR];
    for (int i=0; i<nR; i++)
    {
        maze[i] = new uint8_t[nC];
    }*/

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

    int i=0;
    //cout << "Setting cells to 15" << endl;
    for (int r=0; r<nR; r++)
    {
        for (int c=0; c<nC; c++)
        {
            maze[r][c] = 15;
        }
    }
    //cout << "Creating disjoint set and sampler" << endl;
    DisjointSet ds(nR*nC);
    Sampler sampler(4*nR*nC);

    i=0;
    cout << (nR*nC-1) << endl;
    while (i<(nR*nC-1))
    {
        do {
            do {
                cout << i << endl;
                //cout << "Getting e,d,c,r" << endl;
                e = sampler.sample();
                d = e % 4;
                c = ((e - d)/4) % nC;
                r = (((e - d)/4) - c)/nC;
                cout << "e=" << e << " d=" << d << " c=" << c << " r=" << r << endl;
            }
            while (WallsAbsent(nR, nC, maze, r, c, d) || WallsExterior(r, c, d, nR, nC));
            // (r,c) = (r*nC + c)
            currentR = r;
            currentC = c;
            cell1 = (currentR*nC + currentC);
            cout << "Current cell=" << cell1 << endl;
            
            aR = r;
            aC = c;
            switch (d)
            {
                case 0:     // adjacent cell is up
                    aR++;
                    cell2 = (aR*nC + aC);
                    break;
                case 1:     // adjacent cell is right
                    aC++;
                    cell2 = (aR*nC + aC);
                    break;
                case 2:     // adjacent cell is down
                    aR--;
                    cell2 = (aR*nC + aC);
                    break;
                case 3:     // adjacent cell is left
                    aC--;
                    cell2 = (aR*nC + aC);
                    break;
            }
            cout << "Adjacent cell=" << cell2 << endl;

            //GetAdjacentCell(r, c, d, cell2, nC, &aR, &aC);
            cout << "find(cell1)=" << ds.find(cell1) << endl;
            cout << "find(cell2)=" << ds.find(cell2) << endl;
        }
        while (ds.find(cell1) == ds.find(cell2));
        cout << "Joining cell1 and cell2" << endl;
        ds.join(cell1, cell2);
        cout << "i++" << endl;
        i++;

        // Remove BOTH walls
        // visit two cells of the maze matrix and clear a single bit from each
        //cout << "Removing first wall" << endl;
        uint8_t firstWall = 0x01 << d;
        maze[r][c] &= (~firstWall);
        //cout << "Removing second wall" << endl;
        int cell2dir = cell2 % 4;
        uint8_t secondWall = 0x01 << cell2dir;
        maze[aR][aC] &= (~secondWall);
    }
}
/*
void FindPath(uint8_t **maze)
{
    // push (0,0,0) to stack as (r,c,d)
    // mark (0,0) as visited

    while (true)
    {
        // (r,c,d) = stack.peek();
        if ((r == nR-1) && (c == nC-1))
        {
            break;
        }
        
        if (d==4)
        {
            // mark (r,c) as a dead end
            // stack.pop();
        }
        else
        {
            // (r',c') is next cell in direction d
            // switch statement block for that?

            // push (r,c,d+1) to stack
            if (( no wall exists in direction d ) && ( (r',c') has not been visited ))
            {
                // push (r',c',0) to stack
                // mark (r',c') as visited
            }
        }
    }
}
*/
void PrintMaze(int nR, int nC, uint8_t **maze)
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
                line1 += "   ";
            }
            if((maze[r][c] & 0x04) != 0)
            {
                line2 += "# ";
            }
            else
            {
                line2 += "  ";
            }
            if ((maze[r][c] & 0x2) != 0)
            {
                line2 += "#";
            }
            else
            {
                line2 += " ";
            }
            if ((maze[r][c] & 0x08) != 0)
            {
                line3 += "###";
            }
            else
            {
                line3 += "   ";
            }
        }
        cout << line1 << endl;
        cout << line2 << endl;
        cout << line3 << endl;
    }
}
// User input from argc and argv
int main(int argc, char *argv[])
{
    // Number of row and columns
    int32_t nR, nC;

    nR = strtol(argv[1],nullptr,10);
    nC = strtol(argv[2],nullptr,10);
    //cout << nR << ' ' << nC << endl;

    // All items in "universe"
    const int32_t allWalls = (nR * nC * 4);

    // Array of all items
    int32_t items[10000];
    // Initialize array with "wall addresses"
    for (int i=0; i<allWalls; i++)
    {
        items[i] = i;
    }
    cout << "point 1" << endl;
    // Allocate space for maze
    // Maze array size depends on user inputs
    //cout << "Building maze["<<nR<<"]["<<nC<<"]"<<endl;
    uint8_t **maze;
    maze = new uint8_t*[nR];
    for (int i=0; i<nR; i++)
    {
        maze[i] = new uint8_t[nC];
    }


    cout << "Generating maze" << endl;
    GenerateMaze(nR, nC, maze);
    cout << "Printing maze" << endl;
    PrintMaze(nR, nC, maze);

    //FindPath(maze);


    // Delete maze
    /*for (int i=0; i<nR; i++)
    {
        delete [] maze[i];
    }
    delete [] maze;*/

    return 0;
}