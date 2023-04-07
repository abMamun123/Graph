/**
 *author:Abu Jafar Shiddik
 *created:03-04-2023(17:50:19)
 **/
#include <bits/stdc++.h>
using namespace std;
int node,edge;
int const n = 1000;
vector<int>adj_list[n];
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
        for (int adj_node : adj_list[front])
        {
            if (visited[adj_node]==0)
            {
                visited[adj_node] = 1;
                q.push(adj_node);
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
        adj_list[u].push_back(v);
    }
    bfs(0);
    return 0;
}