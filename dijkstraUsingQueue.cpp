/**
 *author:Abu Jafar Shiddik
 *created:07-04-2023(17:35:29)
4 4
0 1 5
1 2 7
1 3 2
2 3 1

4 4
1 2 5
2 3 7
2 4 2
3 4 1
 **/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e5;
int d[N];
vector<pair<int, int>> adj_list[N];
int node, edge;
void dijkstra(int src)
{
    for (int i = 1; i <= node; i++)
    {
        d[i] = INF;
    }
    d[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (auto ad : adj_list[parent])
        {
            int u = ad.first;
            int w = ad.second;
            if (d[parent] + w < d[u])
            {
                d[u] = d[parent] + w;
                q.push(u);
            }
        }
    }
}

int main()
{

    cin >> node >> edge;

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 1;
    dijkstra(src);

    for (int i = 1; i <= node; i++)
    {
        cout << "shortest path from " << src << " to " << i << " is " << d[i] << endl;
    }
    cout << endl;
    return 0;
}