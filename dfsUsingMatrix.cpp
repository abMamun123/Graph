/**
 *author:Abu Jafar Shiddik
 *created:07-04-2023(00:06:10)
**/
#include <bits/stdc++.h>
using namespace std;
int const n = 1000;
int node;
cin>>node;
int adj_matrix[node][node];
int visited[n];
void DFS(src){
    visited[src] = 1;
    cout<<src<<" ";
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
           if(adj_matrix[i][j]==1){
            visited[]
           } 
        }
    }
    
};
int main(){
    for (int i = 0; i < node; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
    DFS(0);
return 0;
}