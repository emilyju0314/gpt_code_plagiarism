#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> u, v;

int dfs(int node, int parent, vector<int>& black) {
    int ways = 1;
    for (int child : adj[node]) {
        if (child == parent) continue;
        int num_black = dfs(child, node, black);
        if (black[node] && black[child]) ways *= (1 << num_black);
        else ways *= ((1 << num_black) - 1);
    }
    return ways;
}

int main() {
    cin >> N;
    adj.resize(N+1);
    u.resize(N);
    v.resize(N);
    
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    cin >> M;
    u.resize(M);
    v.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> u[i] >> v[i];
    }
    
    int ans = 0;
    for (int mask = 0; mask < (1 << M); mask++) {
        vector<int> black(N+1, 0);
        for (int i = 0; i < M; i++) {
            if (mask & (1 << i)) {
                black[u[i]] = 1;
                black[v[i]] = 1;
            }
        }
        ans += dfs(1, 0, black);
    }
    
    cout << ans << endl;
    
    return 0;
}