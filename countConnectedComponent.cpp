/**
 *author:Abu Jafar Shiddik
 *created:21-03-2023(06:14:44)
 **/
#include <bits/stdc++.h>
using namespace std;
const int n = 1e5;
vector<int> adj_list[n];
int visited[n];

void dfs(int node)
{
    visited[node] = 1;
    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
            dfs(adj_node);
    }
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    for (int i = 1; i <= edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int count=0;
    for (int i = 0; i < node; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            count++;
        }
    }
    cout <<"total component: "<< count << endl;
    return 0;
}