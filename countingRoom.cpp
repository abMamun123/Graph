#include<bits/stdc++.h>
using namespace std;
const int sz = 2e5 + 2;
vector<int>ar[sz];
vector<bool>visited(sz,true);
vector<int>color(sz);
bool dfs(int node)
{
visited[node] = false;
for(int iter : ar[node]){
if(visited[iter]){
if(color[node] == 1) color[iter] = 2;
else color[iter] = 1;
bool bicolor_able = dfs(iter);
if(!bicolor_able) return false;
}
else
if(color[node] == color[iter])
return false;
}
return true;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
int nodes , edges ;
cin >> nodes >> edges;
for(int i = 0 ;i<edges;i++){
int a,b;
cin >> a >> b;
ar[a].push_back(b);
ar[b].push_back(a);
}
bool ok = true;
for(int i =1;i<=nodes;i++){
if(visited[i]){
color[i] = 1;
bool is_ok = dfs(i);
if(!is_ok)
ok = false;
}
}
if(ok)
for(int i =1;i<=nodes;i++)
cout<<color[i]<<" ";
else
cout<<"IMPOSSIBLE";
cout<<"\n";
return 0;
}