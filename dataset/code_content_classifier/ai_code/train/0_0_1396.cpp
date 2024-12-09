#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 5e5 + 5;
vector<int> adj[MAX_N];
vector<int> weights;
long long dp[MAX_N][2];
int n;

void dfs(int u, int parent) {
    dp[u][0] = dp[u][1] = 0;
    
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        
        // calculate the value for dp[u][0]
        dp[u][0] += max(dp[v][0] + weights[v], dp[v][1] + weights[v]);
        
        // calculate the value for dp[u][1]
        dp[u][1] += dp[v][0] + 2 * weights[v];
    }
}

int main() {
    cin >> n;
    weights.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    
    cout << max(dp[0][0], dp[0][1]) << endl;
    
    return 0;
}