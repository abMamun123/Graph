#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n + 1];

    // connected node
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    // print list
    int adj_matrix[n + 1][n + 1] = {};
    // memset(adj_matrix, 0, sizeof(adj_matrix));
    for (int i = 0; i <= n; i++)
    {
        cout << i << "->"<< " ";
        for (auto j : adj_list[i])
        {
            // int var = adj_list[i][j];
            adj_matrix[i][j] = 1;
            adj_matrix[j][i] = 1;
            cout << j << " ";
        }
        cout << endl;
    }
    // print matrix
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
