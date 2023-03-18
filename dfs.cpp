/**
 *author:Abu Jafar Shiddik
 *created:10-03-2023(23:58:33)
 **/
/*
2 1
1 4
4 5
4 3
3 6
*/ 
/*
    2 1
    2 3
    2 6
    1 4
    1 6
    3 4
    3 6
    4 5
*/ 
#include <bits/stdc++.h>
using namespace std;
#define max 10000
vector<int> adj_list[max];
bool visited[max];
void dfs(int node)
{
    visited[node] = true;
    cout << node << " ";
    for (auto it : adj_list[node])
    {
        if (!visited[it])
        {
            dfs(it);
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
    // for (int i = 1; i < n; i++)
    // {
    //     if (!visited[i])
    //         dfs(i);
    // }
    dfs(2);
    return 0;
}