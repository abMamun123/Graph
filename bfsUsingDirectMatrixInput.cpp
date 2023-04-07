/**
 *author:Abu Jafar Shiddik
 *created:06-04-2023(22:17:19)
 **/
#include <bits/stdc++.h>
using namespace std;
int node=4;
int adj_matrix[node][node];
int visited[node];
void bfs(int node)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    while (!q.empty())
    {
        int front = q.front();
        cout << front << " ";
        q.pop();
        for (int i = 0; i < node; i++)
        {
            if (adj_matrix[front][i] == 1 and visited[i] == 0){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
};
int main()
{
  
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cin >> adj_matrix[i][j];
        }
    }
    bfs(0);
    return 0;
}