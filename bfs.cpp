/**
 *author:Abu Jafar Shiddik
 *created:18-03-2023(10:07:22)
 **/
#include <bits/stdc++.h>
using namespace std;
const int n = 1e5;
vector<int> adj_list[n];
int visited[n];
int level[n];//new line added
void BFS(int src)
{
    queue<int> q;
    visited[src] = 1;
    level[src] = 0;//new line added
    q.push(src);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        // cout << front << " ";
        for (int adj_node : adj_list[front])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                level[adj_node] = level[front] + 1;//new line added
                q.push(adj_node);
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
    for (int i = 1; i <= n; i++)
    {
        cout<<"node "<<i<<"-->""level:"<<level[i]<<"\n";
    }
    
    return 0;
}
