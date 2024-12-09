#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<vector<int>> adj;
vector<int> depth;
vector<int> parent;
vector<int> dist;
vector<int> result;

void dfs(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u, d+1);
        }
    }
}

int findLCA(int a, int b) {
    while(a != b) {
        if(depth[a] > depth[b]) {
            a = parent[a];
        } else {
            b = parent[b];
        }
    }
    return a;
}

int main() {
    cin >> n >> k;
    adj.resize(n+1);
    depth.resize(n+1, 0);
    parent.resize(n+1, 0);
    dist.resize(n+1, 0);

    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);

    int cnt = 0;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            int lca = findLCA(i, j);
            dist[i] = max(dist[i], depth[i] + depth[j] - 2 * depth[lca]);
            if(dist[i] <= k) {
                result.push_back(i);
                result.push_back(j);
                cnt++;
                if(cnt == 10*n) break;
            }
        }
        if(cnt == 10*n) break;
    }

    cout << cnt << endl;
    for(int i=0; i<cnt*2; i+=2) {
        cout << result[i] << " " << result[i+1] << endl;
    }

    return 0;
}