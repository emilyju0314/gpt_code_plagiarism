#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MOD = 1000000007;

vector<vector<int>> adj;
vector<vector<int>> sccs;
vector<int> cost;
vector<bool> visited;
vector<int> dp;
vector<int> inDegrees;
vector<long long> ways;
stack<int> st;
int n, m;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    st.push(u);
}

void dfs2(int u, int scc_num) {
    sccs[scc_num].push_back(u);
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs2(v, scc_num);
        }
    }
}

void solve() {
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    adj.assign(n + 1, {});
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    visited.assign(n + 1, false);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            sccs.push_back({});
            dfs2(u, sccs.size() - 1);
        }
    }

    dp.assign(sccs.size(), 0);
    inDegrees.assign(sccs.size(), 0);
    for (int i = 0; i < sccs.size(); i++) {
        int minCost = 2e9;
        for (int j : sccs[i]) {
            minCost = min(minCost, cost[j]);
        }
        for (int j : sccs[i]) {
            if (cost[j] == minCost) {
                dp[i] += minCost;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cost[i] = dp[i - 1];
    }

    ways.assign(sccs.size(), 0);
    ways[0] = 1;
    for (int i = 0; i < sccs.size(); i++) {
        for (int j : sccs[i]) {
            for (int k : adj[j]) {
                int v = 0;
                for (int l = 0; l < sccs.size(); l++) {
                    if (sccs[l].size() > 0 && sccs[l][0] == k) {
                        v = l;
                        break;
                    }
                }
                if (i != v) {
                    inDegrees[v]++;
                }
            }
        }
    }

    for (int i = 0; i < sccs.size(); i++) {
        if (inDegrees[i] == 0) {
            dfs(i);
        }
    }

    long long minCost = 0;
    long long numWays = 1;
    for (int i = 0; i < sccs.size(); i++) {
        if (ways[i] == 0) {
            continue;
        }
        minCost += cost[sccs[i][0]];
        numWays = (numWays * ways[i]) % MOD;
    }

    cout << minCost << " " << numWays << endl;
}

int main() {
    cin >> n;
    cost.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    cin >> m;
    solve();

    return 0;
}