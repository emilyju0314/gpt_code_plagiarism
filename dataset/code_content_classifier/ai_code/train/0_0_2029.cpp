#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<int> depth;

void dfs(int u, int d) {
    depth[u] = d;
    for(int v : adj[u]) {
        dfs(v, d+1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    parent.resize(n+1);
    depth.resize(n+1);

    for(int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        for(int j = 0; j < l; j++) {
            int child;
            cin >> child;
            adj[i].push_back(child);
            parent[child] = i;
        }
    }

    dfs(1, 0);

    for(int i = 0; i < m; i++) {
        int type, v;
        cin >> type >> v;

        if(type == 1) {
            int u;
            cin >> u;
            int dist = 0;
            while(v != u) {
                if(depth[v] > depth[u]) {
                    v = parent[v];
                } else {
                    u = parent[u];
                }
                dist++;
            }
            cout << dist << endl;
        } else if(type == 2) {
            int h;
            cin >> h;
            while(h > 1 && depth[v] - h + 1 >= 0) {
                v = parent[v];
                h--;
            }
            cout << v << endl;
        } else if(type == 3) {
            for(int j = n; j >= 1; j--) {
                if(depth[j] == v) {
                    cout << j << endl;
                    break;
                }
            }
        }
    }

    return 0;
}