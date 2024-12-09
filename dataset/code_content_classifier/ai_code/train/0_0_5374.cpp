#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> weights;
vector<vector<int>> adj_list;
vector<int> dp;
vector<int> count;

void dfs(int u, int parent) {
    dp[u] = weights[u];
    count[u] = 1;
    
    for (int v : adj_list[u]) {
        if (v != parent) {
            dfs(v, u);
            dp[u] += max(0, dp[v]);
            count[u] += max(0, count[v]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    weights.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    
    adj_list.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    dp.resize(n);
    count.resize(n);
    
    dfs(0, -1);
    
    long long numer = 0, denom = 0;
    for (int i = 0; i < n; ++i) {
        numer = max(numer, (long long)dp[i]);
        denom = max(denom, (long long)count[i]);
    }
    
    cout << numer << " " << denom << "\n";
    
    return 0;
}