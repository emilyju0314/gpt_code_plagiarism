#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int inA[MAXN], inB[MAXN], subtreeSize[MAXN];

void dfs(int u, int par) {
    subtreeSize[u] = 1;

    for(int v : adj[u]) {
        if(v != par) {
            dfs(v, u);
            subtreeSize[u] += subtreeSize[v];
            inA[u] += inB[v];
            inB[u] += inA[v];
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += inA[i] * (n - subtreeSize[i]) + inB[i] * (n - subtreeSize[i]);
    }

    cout << ans / 2 << endl;

    return 0;
}