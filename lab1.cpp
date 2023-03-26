#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> adj_list[n];
    int adj_matrix[n][n] = {};

    adj_matrix[0][1] = 1;
    adj_matrix[0][2] = 1;

    adj_matrix[1][0] = 1;
    adj_matrix[1][3] = 1;
    adj_matrix[1][4] = 1;

    adj_matrix[2][0] = 1;
    adj_matrix[2][5] = 1;

    adj_matrix[3][1] = 1;
    adj_matrix[3][4] = 1;
    adj_matrix[3][5] = 1;

    adj_matrix[4][1] = 1;
    adj_matrix[4][3] = 1;

    adj_matrix[5][2] = 1;
    adj_matrix[5][3] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_matrix[i][j] == 1)
            {
                adj_list[i].push_back(j);
            }
        }
    }
    // print list
    for (int i = 0; i < n; i++)
    {
        cout << i << "-->";
        for (int j : adj_list[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}
