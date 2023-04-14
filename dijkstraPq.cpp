/**
 *author:Abu Jafar Shiddik
 *created:10-04-2023(13:44:11)
5 6
1 2 6
1 3 0
1 4 3
2 5 1
3 2 1
4 5 0
 **/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e5 + 5;
const ll INF = (ll)9e18;
vector<bool> visited(maxN);
int parent[maxN];
int level[maxN];
vector<pair<int, int>> adj_list[maxN];
ll dist[maxN];
void dijkstra(int src, int nodes)
{
    for (int i = 1; i <= nodes; i++)
    {
        dist[i] = INF;
    }
    dist[src] = 0;
    level[src] = 1;
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
                parent[v] = u;
                level[v] = level[u] + 1;
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
    int src = 1;
    int dest_node = nodes;
    dijkstra(src, nodes);

    for (int i = 1; i <= nodes; i++)
    {
        cout << "destination of "<< "1" << " to " << i << " is " << dist[i] << endl;
    }
    // cout << level[dest_node] << "\n";
    int selected_node = dest_node;
    vector<int> path;
    while (true)
    {
        path.push_back(selected_node);
        if (selected_node == src)
        {
            break;
        }
        selected_node = parent[selected_node];
    }

    reverse(path.begin(), path.end());
    cout<<"total node "<<path.size()<<"\n";
    for (int node : path)
    {
        cout << node << " ";
    }
    cout << '\n';

    return 0;
}