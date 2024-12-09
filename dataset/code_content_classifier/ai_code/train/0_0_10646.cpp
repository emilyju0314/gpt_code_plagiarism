#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int N, B;
int dp[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int p) {
    vector<int> subtree_costs;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            subtree_costs.push_back(dp[v]);
        }
    }
    sort(subtree_costs.begin(), subtree_costs.end());
    dp[u] = 1;
    for (int i = 0; i < subtree_costs.size(); i++) {
        dp[u] = max(dp[u], subtree_costs[i] + (int) subtree_costs.size() - i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int case_num = 1;
    while (true) {
        cin >> N >> B;
        if (N == 0 && B == 0) {
            break;
        }
        
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        
        for (int i = 2; i <= N; i++) {
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
        
        dfs(1, 0);
        
        cout << "Case " << case_num << ":\n";
        for (int i = 1; i <= N; i++) {
            cout << dp[i] << "\n";
        }
        
        case_num++;
    }
    
    return 0;
}