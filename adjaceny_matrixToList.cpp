#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n + 1];
    int adj_matrix[n + 1][n + 1] = {};
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for (int i = 1; i <= e; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << "-->"
             << " ";
        for (auto j : adj_list[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
