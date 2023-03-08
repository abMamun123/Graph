/**
 *author:Abu Jafar Shiddik
 *created:08-03-2023(11:19:30)
 **/
/*
    0------1
          / \
          2--3
      
    0-1
    1-0
    1-2
    1-3
    2-1
    2-3
    3-1
    3-2

    0 1 0 0 
    1 0 1 1 
    0 1 0 1 
    0 1 1 0 

    nodes = 4
    time complexity->O(n^2)   A-----B(n number of edges can include each node)
    tc = O(E) = because we just count how many nodes are direct conncted by each edge
    in worst case it can be, E = n^2
    same for space complexity 
    space complexity->O(n^2)
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nodes = 4;
    int matrix[nodes][nodes] = {};
    matrix[0][1] = 1;

    matrix[1][0] = 1;
    matrix[1][2] = 1;
    matrix[1][3] = 1;

    matrix[2][1] = 1;
    matrix[2][3] = 1;

    matrix[3][1] = 1;
    matrix[3][2] = 1;

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}