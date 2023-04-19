/**
 *author:Abu Jafar Shiddik
 *created:16-04-2023(02:12:36)
 **/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
const long long INF = 1e18;
long long matrix[N][N];
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            matrix[i][j] = INF;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        matrix[u][v] = min(matrix[u][v], w);
        matrix[v][u] = min(matrix[v][u], w);
    }

    for (int i = 1; i <= n; i++)
    {
        matrix[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                matrix[u][v] = min(matrix[u][v], matrix[u][k] + matrix[v][k]);
            }
        }
    }

    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;

        if(matrix[u][v] == INF)
            cout<<"-1\n";
        else{
            cout<<matrix[u][v]<<"\n";
        } 
    }

    return 0;
}