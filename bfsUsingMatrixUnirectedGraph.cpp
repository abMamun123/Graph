/**
 *author:Abu Jafar Shiddik
 *created:18-03-2023(10:07:22)
 **/
#include <bits/stdc++.h>
using namespace std;
int node, edge;
const int n = 1000;
int adj_matrix[n][n];
int visited[n];
void BFS(int src)
{
    queue<int> q;
    visited[src] = 1;
    q.push(src);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        cout << head << " ";
        for (int i = 0; i < node; i++)
        {
            if (adj_matrix[head][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
};
int main()
{
    cin >> node >> edge;
    for (int i = 1; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
    BFS(0);
    return 0;
}
