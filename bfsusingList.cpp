/**
 *author:Abu Jafar Shiddik
 *created:03-04-2023(14:59:17)
 **/
#include <bits/stdc++.h>
using namespace std;
int const n = 10000;
int visited[n];
vector<int> adj_list[n];
void BFS(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        cout << head << " ";

        for (int adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
};
int main()
{
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    BFS(0);
    return 0;
}