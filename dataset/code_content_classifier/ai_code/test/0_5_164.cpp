#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> adj;
vector<string> label;
vector<string> subtree_str;
vector<vector<string>> dp;

void dfs(int u) {
    subtree_str[u] = label[u];
    for (int v : adj[u]) {
        dfs(v);
        subtree_str[u] += subtree_str[v];
    }
}

string solve(int u, int k) {
    if (dp[u][k] != "") {
        return dp[u][k];
    }

    if (u == 0) {
        return "";
    }

    string res;
    if (k > 0) {
        string without_dup = solve(adj[u][0], k) + label[u] + solve(adj[u][1], k);
        string with_dup = solve(adj[u][0], k - 1) + label[u] + label[u] + solve(adj[u][1], k);
        res = min(without_dup, with_dup);
    } else {
        res = solve(adj[u][0], k) + label[u] + solve(adj[u][1], k);
    }

    return dp[u][k] = res;
}

int main() {
    int n, k;
    cin >> n >> k;

    adj.resize(n + 1);
    label.resize(n + 1);
    subtree_str.resize(n + 1);
    dp.assign(n + 1, vector<string>(k + 1, ""));

    string initial_labels;
    cin >> initial_labels;
    for (int i = 1; i <= n; i++) {
        label[i] = initial_labels[i-1];
    }

    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        adj[i].push_back(l);
        adj[i].push_back(r);
    }

    dfs(1);

    string ans = solve(1, k);
    cout << ans << endl;

    return 0;
}