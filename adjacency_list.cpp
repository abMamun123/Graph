/**
 *author:Abu Jafar Shiddik
 *created:08-03-2023(12:20:54)
 **/

/*
        5
    0------->1
          4/ \9
          2---3
            6

    0 -->1
    1 --> 0,2,3
    2 -->1,3
    3 -->1,2

    0 -->{1,5}
    1 --> {0,5},{2,4},{3,9}
    2 -->{1,4},{3,6}
    3 -->{1,9} {2,6}
*/
#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> adj_list[n+1];
//     int e;
//     cin >> e;
//     for (int i = 1; i <= e; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj_list[u].push_back(v);
//         adj_list[v].push_back(u);
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         cout << i << "-->";
//         for (auto j : adj_list[i])
//         {
//             cout << j << " ";
//         }
//         cout<<"\n";
//     }

//     return 0;
// }

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> adj_list[n + 1];
    int e;
    cin >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v,w});
    }

    for (int i = 0; i <= n; i++)
    {
        cout << i << "-->";
        for (auto j : adj_list[i])
        {
            cout <<"{"<<j.first<<","<<j.second<< "}"<<" ";
        }
        cout << "\n";
    }

    return 0;
}