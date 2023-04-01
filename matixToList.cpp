/**
 *author:Abu Jafar Shiddik
 *created:01-04-2023(23:47:55)
0 1 0 0
1 0 1 1
0 1 0 1
0 1 1 0
 **/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node;
    cin >> node;
    int adj_matrix[node][node] = {};
    vector<int> adj_list[node];

    // print
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
    // input
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cin >> adj_matrix[i][j];
        }
    }
    // print

    cout << "\n";
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
    // list
    
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            if (adj_matrix[i][j] == 1)
            {
                adj_list[i].push_back(j);
            }
        }
    }
    cout << "\n";
    // print list
    for (int i = 0; i < node; i++)
    {
        cout << i << " -->";
        for (int j : adj_list[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}