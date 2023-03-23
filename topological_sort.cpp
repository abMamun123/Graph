/**
 *author:Abu Jafar Shiddik
 *created:22-03-2023(23:32:34)
 **/
/*
1 2 
3 1
4 5
*/
#include <bits/stdc++.h>
using namespace std;
const int n = 1e5;
int visited[n];
vector<int> adj_list[n];
stack<int> st;

void dfs(int node){
    visited[node] = 1;
    for (int adj_node:adj_list[node])
    {
        if(visited[adj_node]==0){
            dfs(adj_node);
        }
    }
    st.push(node);
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    for (int i = 1; i <= node; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
        }
    }
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}