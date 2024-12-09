#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

const int MAXN = 2.5e5 + 5;
vector<int> adj[MAXN];
bool vis[MAXN];
unordered_set<int> cycle;
int components;

void dfs(int u, int p) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(v == p) continue;
        if(vis[v]) {
            cycle.insert(v);
            cycle.insert(u);
        } else {
            dfs(v, u);
        }
    }
}

void dfs2(int u) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!cycle.count(v) && !vis[v]) {
            dfs2(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long ans = 0;

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            components++;
            cycle.clear();
            dfs(i, -1);

            for(int v : cycle) {
                vis[v] = false;
            }

            for(int v : cycle) {
                if(!vis[v]) {
                    dfs2(v);
                }
            }

            ans += (long long) cycle.size() * (cycle.size() - 1) / 2;
        }
    }

    ans += (long long) m * (m + 1) / 2 - components;

    cout << ans << endl;

    return 0;
}