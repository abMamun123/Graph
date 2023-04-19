/*
5 7
1 2 3
1 3 2
2 3 1
2 4 8
2 5 5
4 1 2
4 5 2

4 5
1 2 2
2 3 2
1 4 1
3 1 -7
3 4 -2

*/
#include <bits/stdc++.h>
using namespace std;
int INF = 1e9 + 5;
const int maxN = 1e5 + 5;
int dist[maxN];
bool detect_cycle = false;
int parent[maxN];
int last_visited_node = -1;
int n, m;
vector<pair<int, int>> adj_list[maxN];
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
                    parent[v] = u;
                    dist[v] = dist[u] + cost;
                    if (i == n)
                    {
                        last_visited_node = v;
                        detect_cycle = true;
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
    BF(src);
    if (detect_cycle)
    {
        cout<<"YES\n";
        vector<int>cycle;
        int selected_node = last_visited_node;
        int first_node = selected_node;
        for (int i = 1; i <= n-1; i++)
        {
            selected_node = parent[selected_node];
        }
        cycle.push_back(selected_node);
        while (true)
        {
            selected_node = parent[selected_node];
            cycle.push_back(selected_node);
            if(selected_node == first_node)
                break;
        }
        reverse(cycle.begin(),cycle.end());
        for(auto node : cycle){
            cout<<node<<" ";
        }
        
    }
    else
    {
        cout << "NO";
    }
}