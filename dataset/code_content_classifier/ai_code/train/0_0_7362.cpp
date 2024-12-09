#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> edges(n-1);
    vector<int> deg(n+1, 0);

    for(int i = 0; i < n-1; i++) {
       cin >> edges[i].first >> edges[i].second;
       deg[edges[i].first]++;
       deg[edges[i].second]++;
    }

    vector<vector<int>> adj_list(n+1);
    for(auto &edge : edges) {
        if(deg[edge.first] > 1 && deg[edge.second] > 1) {
            cout << "NO" << endl;
            return 0;
        }
        adj_list[edge.first].push_back(edge.second);
        adj_list[edge.second].push_back(edge.first);
    }

    queue<int> q;
    vector<int> vis(n+1, 0);
    q.push(1);
    vis[1] = 1;

    vector<pair<int, int>> tree_edges;
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto &neighbor : adj_list[node]) {
            if(!vis[neighbor]) {
                vis[neighbor] = 1;
                q.push(neighbor);
                tree_edges.push_back({node, neighbor});
            }
        }
    }

    cout << "YES" << endl;
    for(auto &edge : tree_edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}