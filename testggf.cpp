#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+5;

int visited[N];
int cycle[N];
vector<int> adj_list[N];

bool DFS(int node)
{
    visited[node]=1;

    for(int adj_node: adj_list[node])
    {
        if(visited[adj_node]==0)
        {
            //assign alternative cycle
            if(cycle[node]==1)
            {
                cycle[adj_node]=2;
            }
            else
            {
                cycle[adj_node]=1;
            }

            bool is_cycle = DFS(adj_node);
            if(!is_cycle)
            {
                return false;
            }
        }
        else
        {
            if(cycle[node]==cycle[adj_node])
            {
                return false;
            }

        }
    }
    return true;
}

int main()
{
    //DFS input
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }


    bool is_cycle =true;
    for(int i=1; i<=nodes; i++)
    {
        if(visited[i]==0)
        {
            cycle[i]=1;
            bool ok= DFS(i);
            if(!ok)
            {
                is_cycle=false;
                break;
            }
        }
    }
    if(!is_cycle)
    {
        cout<<"Cycle Exist"<<"\n";
    }
    else
    {
        cout<<"No Cycle";
    }
    return 0;
}