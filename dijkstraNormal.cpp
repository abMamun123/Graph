/**
 *author:Abu Jafar Shiddik
 *created:07-04-2023(17:35:29)
**/
#include <bits/stdc++.h>
using namespace std;
const int n = 1e5 + 5;
const int INF = 1e9
int d[INF],int visited[n];
vector<pair<int,int>>adj_list[n];
int node,edge;
void dijkstra(src){

};
int main(){
    cin>>node>>edge;
    for (int i = 0; i < edge; i++)
    {
        int u,v,w;
        cin>>u>>v,w;
        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});
        int src = 2;
        dijkstra(src);
    }
    
return 0;
}