#include<bits/stdc++.h>
using namespace std;
/*
6
0 0 0 0 0 0 0
0 0 1 1 0 0 0
0 1 0 0 1 0 0
0 1 0 0 1 0 0
0 0 1 1 0 1 1
0 0 0 0 1 0 0
0 0 0 0 1 0 0
*/ 
int main()
{
    int x;

    cin >> x;

    int mat[x+1][x+1];

    for(int i=0; i<=x; i++)
        for(int j=0; j<=x; j++)
            mat[i][j] = 0;


    for(int i=0; i<=x; i++)
        for(int j=0; j<=x; j++)
            cin >> mat[i][j];


    vector<int> adj_list[x+1];

    for(int i=0; i<=x; i++)
    {
        for(int j=0; j<=x; j++)
        {
            if(mat[i][j] == 1)
            {
                adj_list[i].push_back(j);
            }
        }
    }

    for(int i=0; i<=x; i++)
    {
        cout<< i <<"->";

        for(auto j : adj_list[i])
            cout<< j <<" ";
        cout<<"\n";
    }




    return 0;
}