/**
 *author:Abu Jafar Shiddik
 *created:17-03-2023(10:34:14)
 **/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int matrix[n][n] = {};
    vector<int> adj_list[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1 || matrix[j][i] == 1)
            {
                adj_list[i].push_back(j);
                adj_list[j].push_back(i);
            }
        }
    }
    // print list
    for (int i = 0; i < n; i++)
    {
        cout << i << "---->";
        for (auto j : adj_list[i])
            cout << j << " ";
    }
    cout << "\n";
    return 0;
};