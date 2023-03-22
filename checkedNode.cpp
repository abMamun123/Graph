/**
 *author:Abu Jafar Shiddik
 *created:18-03-2023(10:07:22)
 **/
#include <bits/stdc++.h>
using namespace std;
int node, edge;
const int n = 1000;
vector<int> adj_list[n];
map<int, int> mp;
int visited[n];
int level[n]; // new line added
void BFS(int src)
{
    queue<int> q;
    visited[src] = 1;
    level[src] = 0; // new line added
    q.push(src);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        visited[head] = 1;
        cout << head << " ";
        for (int adj_node : adj_list[head])
        {
            mp[adj_node]++;
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1; // new line added
                q.push(adj_node);
            }
        }
    }
};
int main()
{
    cin >> node >> edge;
    for (int i = 1; i <= edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    BFS(0);
    cout<<"\n";
    for (auto it:mp)
    {
        cout <<it.first<<"-->"<<it.second<< "\n";
    }

    return 0;
}
