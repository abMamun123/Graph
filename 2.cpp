/**
 *author:Abu Jafar Shiddik
 *created:21-03-2023(08:09:41)
 **/
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
const int n = 1e5;
int node = 6;
vector<int> adj_list[n];
adj_list[0] = {1,3,4};
adj_list[1] = {0,2,5};
adj_list[2] = {1,4};
adj_list[3] = {0};
adj_list[4] = {2,5};
adj_list[5] = {1,4};
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
        for(int adj_node : adj_list[head]){
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
    for (int i = 0; i < node; i++)
    {
        if(visited[i]==0)
            bfs(0);
    }
    
    for (int i = 0; i < node; i++)
    {
        cout<<"node "<<i<<" level :"<<level[i]<<"\n";
    }
    return 0;
}
/*
6 7
0 1
0 3
0 4
1 2
1 5
2 4
5 4
*/ 
