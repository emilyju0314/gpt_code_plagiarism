#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1e6+5;

vector<int> adj[MAXN];
int depth[MAXN];

int dfs(int u) {
    if(adj[u].empty()) return 1;

    vector<int> leaves;
    for(int v : adj[u]) {
        depth[v] = depth[u] + 1;
        leaves.push_back(dfs(v));
    }

    sort(leaves.begin(), leaves.end(), greater<int>());
    int ans = 0;
    for(int i = 0; i < leaves.size(); i++) {
        if(i <= k || depth[u] - k > depth[adj[u][i]]) {
            ans += leaves[i];
        }
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    int result = dfs(1);
    cout << result << endl;

    return 0;
}