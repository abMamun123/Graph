/**
 *author:Abu Jafar Shiddik
 *created:21-03-2023(19:39:58)
 **/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;
    int adj_matrix[node+1][node+1] = {};
    for(int i =1;i<=edge;i++){
        int u,v;
        cin>>u>>v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
    //for print the matrix
    // for (int i = 0; i <= node; i++)
    // {
    //     for (int j = 0; j <= node; j++)
    //     {
    //         cout << adj_matrix[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    //for print the adj_node in matrix
    for (int i = 0; i <= node; i++)
    {
        cout<<i<<" adj_node--> ";
        for(int j = 0; j <= node; j++)
        {
            if(adj_matrix[i][j] == 1)
                cout<<j<<" ";
        }
        cout << "\n";
    }
    return 0;
}