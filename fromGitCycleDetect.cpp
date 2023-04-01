#include <bits/stdc++.h>
using namespace std;

const int n = 1e5;
int visited[n];
vector<int> adj_list[n];

bool detect_cycle(int node) {
    visited[node] = 1;
    for (int adj_node : adj_list[node]) {
        if (visited[adj_node] == 0) {
            bool got_cycle = detect_cycle(adj_node);
            if (got_cycle) {
                return true;
            }
        }
        else if (visited[adj_node] == 1) {
            return true;
        }
    }
    visited[node] = 2;
    return false;
}

int main() {
    int node, edge;
    cin >> node >> edge;

    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u); // for undirected graph
    }

    bool exits_cycle = false;
    for (int i = 0; i <node; i++) {
        if (visited[i] == 0) {
            bool got_cycle = detect_cycle(i);
            if (got_cycle) {
                exits_cycle = true;
                break;
            }
        }
    }

    if (exits_cycle) {
        cout << "Cycle Exist";
    }
    else {
        cout << "No Cycle";
    }

    return 0;
}
