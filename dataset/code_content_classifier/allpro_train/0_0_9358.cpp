#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define MOD 1000000007

using namespace std;

int n, m, k;
int total = 0;
vector<int> c;
vector<vector<int>> adj_list;
vector<int> visited;

int power(int a, int b) {
    if (b == 0) return 1;
    int res = power(a, b/2) % MOD;
    res = (res * res) % MOD;
    if (b % 2 == 1) res = (res * a) % MOD;
    return res;
}

void dfs(int u, unordered_set<int> &connected) {
    visited[u] = 1;
    connected.insert(u);
    for (int v : adj_list[u]) {
        if (!visited[v] && (c[u] & c[v]) == 0) {
            dfs(v, connected);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    c.resize(n);
    adj_list.resize(n);
    visited.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            unordered_set<int> connected;
            dfs(i, connected);

            int count = 0;
            for (int j : connected) {
                count += (__builtin_popcount(c[j]) == k);
            }

            total = (total + power(2, count)) % MOD;
        }
    }

    cout << total << endl;

    return 0;
}