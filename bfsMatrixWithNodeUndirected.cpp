/**
 *author:Abu Jafar Shiddik
 *created:03-04-2023(17:50:19)
 **/
#include <bits/stdc++.h>
using namespace std;
int node,edge;
int const n = 1000;
int adj_matrix[n][n];
int visited[n];
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << " ";
        for (int i = 0; i < node; i++)
        {
            if (adj_matrix[front][i] == 1 and visited[i] == 0)
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
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
    bfs(0);
    return 0;
}