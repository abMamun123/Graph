#include <iostream>
#include <vector>

using namespace std;

const int a = 100005;

int n, m;
vector<int> adj[a];
int color[a];

bool dfs(int v, int c)
{
    color[v] = c;

    for (int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        if (color[u] == -1)
        {
            if (!dfs(u, 1 - c))
            {
                return false;
            }
        }
        else if (color[u] == c)
        {
            return false;
        }
    }

    return true;
}

bool isBipartite()
{
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0))
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isBipartite())
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}