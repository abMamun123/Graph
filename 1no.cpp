#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // create adjacency matrix
    int adj_matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj_matrix[i][j];
        }
    }

    // create adjacency list
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_matrix[i][j] == 1)
            {
                adj_list[i].push_back(j);
            }
        }
    }

    // print adjacency list
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            cout << adj_list[i][j] << " ";
        }
        cout <<"\n";
    }

    return 0;
}