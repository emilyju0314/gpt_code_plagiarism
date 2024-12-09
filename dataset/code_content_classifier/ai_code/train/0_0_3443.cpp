#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> children;
vector<int> dp;

void dfs(int u, int parent) {
    children[u] = 1;
    dp[u] = 1;
    
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            children[u] += children[v];
            dp[u] = max(dp[u], children[v]);
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    adj.resize(N + 1);
    children.resize(N + 1);
    dp.resize(N + 1);
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, -1);
    
    int result = *max_element(dp.begin() + 1, dp.end());
    int leaves = 0;
    
    for (int i = 1; i <= N; i++) {
        if (dp[i] == 1) {
            leaves++;
        }
    }
    
    cout << result << " " << leaves << endl;
    
    return 0;
}