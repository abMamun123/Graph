/**
 *author:Abu Jafar Shiddik
 *created:18-03-2023(10:07:22)
 **/
#include <bits/stdc++.h>
using namespace std;
const int n = 1e5;
vector<int> adj_list[n];
int visited[n];
void BFS(int src)
{
    queue<int> q;
    visited[src] = 1;
    q.push(src);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << " ";
        for (int adj_node : adj_list[front])
        {
            if (visited[adj_node] == 0)
            {
                q.push(adj_node);
                visited[adj_node] = 1;
            }
        }
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    BFS(2);
    return 0;
}