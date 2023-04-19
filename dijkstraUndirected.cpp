/**
 *author:Abu Jafar Shiddik
 *created:15-04-2023(13:20:48)

10 10
1 4 201
2 3 238
3 4 40
3 6 231									     
3 8 45
4 5 227
4 6 58
4 9 55
5 7 14
6 10 242

 **/
#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5+5;
vector<pair<int, int>> adj_list[maxN];
const int INF = 1e9 + 5;
int visited[maxN];
int parent[maxN];
int dist[maxN];
int n, m;

void dijkstra(int src)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[src], src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (visited[u] == 1)
            continue;
        visited[u] = 1;
        for (auto adj_node : adj_list[u])
        {
            int v = adj_node.first;
            int edg_cost = adj_node.second;
            if (cost + edg_cost < dist[v])
            {
                dist[v] = cost + edg_cost;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 1;
    int count = 1;
    int dest_node = n;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            count++;
            if (count > 2)
                break;
            dijkstra(i);
        }
    }
    if(count>2)
        cout<<"-1\n";
    else{
        int selected_node = dest_node;
        vector<int>path;
        while (true)
        {
            path.push_back(selected_node);
            if(selected_node == src)
                break;
            selected_node = parent[selected_node];
        }
        reverse(path.begin(),path.end());
        for(auto p : path){
            cout<<p<<" ";
        }
    }
    return 0;
}
