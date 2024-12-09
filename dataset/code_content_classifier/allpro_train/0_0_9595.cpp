#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<int> color(100005, -1);
vector<pair<int, int>> directed_edges;

bool dfs(int u, int c) {
    color[u] = c;
    for(auto v : adj[u]) {
        if(color[v] == -1) {
            if(!dfs(v, c^1)) return false;
        } else if(color[v] == c) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(!dfs(1, 0)) {
        cout << -1 << endl;
    } else {
        for(int u = 1; u <= N; u++) {
            for(auto v : adj[u]) {
                if(color[u] == color[v]) {
                    directed_edges.push_back({u, v});
                }
            }
        }

        for(auto edge : directed_edges) {
            cout << edge.first << " " << edge.second << endl;
        }
    }

    return 0;
}