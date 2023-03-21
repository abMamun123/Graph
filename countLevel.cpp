/**
 *author:Abu Jafar Shiddik
 *created:21-03-2023(08:09:41)
 **/
#include <bits/stdc++.h>
using namespace std;
const int n = 1e5;
vector<int> adj_list[n];
int visited[n];
int level[n];
void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    level[node] = 0;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        cout<<head<<" ";
        for(int adj_node : adj_list[node]){
            if(visited[adj_node] == 0){
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
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
    bfs(1);
    for (int i = 1; i <= node; i++)
    {
        cout<<"node "<<i<<" level :"<<level[i]<<"\n";
    }
    return 0;
}