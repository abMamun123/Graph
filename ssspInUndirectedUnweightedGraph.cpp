/**
 *author:Abu Jafar Shiddik
 *created:07-04-2023(11:14:22)
4 4
0 1
1 2
1 3
2 3
 **/
#include <bits/stdc++.h>
using namespace std;
int const n = 1e5;
int visited[n];
int level[n];
vector<int> adj_list[n];
void SSSP(int src){
    queue<int>q;
    q.push(src);
    level[src] = 0;
    visited[src] = 1;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (int adj_node : adj_list[head])
        {
            if(visited[adj_node]==0){
                level[adj_node] = level[head] + 1;
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
    
};
int main()
{
    int node,edge;
    cin>>node>>edge;
    for (int i = 0; i < edge; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    SSSP(0);
    for (int i = 0; i < node; i++)
    {
        cout<<"sortest path from 0 to "<<i<<" --> "<<level[i]<<endl;
    }
    cout<<"\n";
    for (int i = 0; i < node; i++)
    {
        cout<<"node "<<i<<" level"<<"--> "<<level[i]<<endl;
    }
    return 0;
}