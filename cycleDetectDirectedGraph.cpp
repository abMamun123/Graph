/**
 *author:Abu Jafar Shiddik
 *created:09-04-2023(10:51:33)
 **/
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int visited[N];
vector<int> adj_list[N];
bool detect_cycle(int src)
{
    visited[src] = 1;
    for (auto adj_node : adj_list[src])
    {
        if (visited[adj_node] == 0)
        {
            bool ok = detect_cycle(adj_node);
            if (ok)
            {
                return true;
            }
        }
        if (visited[adj_node] == 1)
        {
            return true;
        }
    }
    visited[src] = 2;
    return false;
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    while (edges--)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    bool cycle = false;
    for (int i = 1; i <= nodes; i++)
    {
        if (visited[i] == 0)
        {
            bool ok = detect_cycle(i);
            if (ok)
            {
                cycle = true;
                break;
            }
        }
    }
    if (cycle == true)
    {
        cout << "Cycle Detected\n";
    }
    else
    {
        cout << "no cycle";
    }
    return 0;
}