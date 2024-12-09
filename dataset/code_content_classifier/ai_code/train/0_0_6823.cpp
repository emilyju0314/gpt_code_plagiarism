#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int dfs(int node, vector<vector<int>>& adj_list, vector<bool>& visited) {
    visited[node] = true;
    int cnt = 1;
    for (int v : adj_list[node]) {
        if (!visited[v]) {
            cnt += dfs(v, adj_list, visited);
        }
    }
    return cnt;
}

int power(int base, int exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        int temp = power(base, exp/2);
        return (1LL * temp * temp) % MOD;
    } else {
        return (1LL * base * power(base, exp-1)) % MOD;
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj_list(n+1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        adj_list[i].push_back(a);
        adj_list[a].push_back(i);
    }

    vector<bool> visited(n+1, false);
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int cnt = dfs(i, adj_list, visited);
            ans = (ans * power(k, cnt)) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}