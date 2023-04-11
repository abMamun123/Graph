/**
 *author:Abu Jafar Shiddik
 *created:10-04-2023(13:44:11)
3 3
1 2 5
2 3 2
1 3 1
 **/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e5 + 5;
const ll INF = (ll)9e18;
vector<bool> visited(maxN);
vector<pair<int, int>> adj_list[maxN];
ll dist[maxN];
void dijkstra(int src, int nodes)
{
    for (int i = 1; i <= nodes; i++)
    {
        dist[i] = INF;
    }
    dist[src] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({dist[src], src});

    while (!pq.empty())
    {
        ll cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;

        for (auto ad : adj_list[u])
        {
            int v = ad.first;
            ll edge_cost = ad.second;
            if ((cost + edge_cost) < dist[v])
            {
                dist[v] = cost + edge_cost;
                pq.push({dist[v], v});
            }
        }
    }
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    while (edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }
    dijkstra(1, nodes);

    for (int i = 1; i <= nodes; i++)
    {
        cout << "shortest path from " << "1" << " to " << i << " is " << dist[i] << endl;
    }
    
    return 0;
}