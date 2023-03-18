/**
 *author:Abu Jafar Shiddik
 *created:18-03-2023(11:06:46)
 **/
#include <bits/stdc++.h>
using namespace std;
const int n = 1e5;
vector<int> adj_list[n];
int visited[n];
void DFS(int src)
{
    cout << src << " ";
    visited[src] = 1;
    for (int adj_node : adj_list[src])
    {
        if (visited[adj_node] == 0)
            DFS(adj_node);
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
    DFS(2);
    return 0;
}