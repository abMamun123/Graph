/**
 *author:Abu Jafar Shiddik
 *created:12-04-2023(12:12:17)
5 6
1 2 -6
1 3 0
1 4 -3
2 5 1
3 2 1
4 5 0
--------------->
cycle check
5 6
1 2 -6
3 1 0 
1 4 -3
2 5 1 
2 3 1 
4 5 0
 **/
#include <bits/stdc++.h>
using namespace std;
int INF = 1e9 + 5;
const int maxN = 1e5 + 5;
int dist[maxN];
int parent[maxN];
int last_visited_node = -1;
bool detect_cycle = false;
vector<pair<int, int>> adj_list[maxN];
int n, m;
void BF(int src)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    dist[src] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            for (auto adj_node : adj_list[node])
            {
                int u = node;
                int v = adj_node.first;
                int cost = adj_node.second;
                if (dist[u] + cost < dist[v])
                {
                    dist[v] = dist[u] + cost;
                    parent[v] = u;
                    if (i == n)
                    {
                        detect_cycle = true;
                        last_visited_node = v;
                    }
                }
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
    }
    int src = 1;
    int dest_node = n;
    BF(src);
    if (detect_cycle)
    {
        cout << "Graph has negative cycle\n";
        int seleted_node = last_visited_node;
        for (int i = 1; i <= n - 1; i++)
        {
            seleted_node = parent[seleted_node];
        }
        vector<int> cycle;
        int first_node = seleted_node;
        cycle.push_back(seleted_node);
        while (true)
        {
            seleted_node = parent[seleted_node];
            cycle.push_back(seleted_node);
            if (seleted_node == first_node)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        cout << "negative cycle "
             << " is : ";
        for (auto node : cycle)
        {
            cout << node << " ";
        }
        cout << "\n\n";
    }
    else
    {
        vector<int> path;
        int seleted_node = dest_node;
        while (true)
        {
            path.push_back(seleted_node);
            if (seleted_node == src)
                break;
            seleted_node = parent[seleted_node];
        }
        reverse(path.begin(), path.end());
        cout << "shortest path from " << src << " to " << dest_node << " is : ";
        for (auto node : path)
        {
            cout << node << " ";
        }
        cout << "\n\n";
        for (int i = 1; i <= n; i++)
        {
            cout << "shortest destination from " << src << " to " << i << " is " << dist[i] << endl;
        }
    }
    return 0;
}