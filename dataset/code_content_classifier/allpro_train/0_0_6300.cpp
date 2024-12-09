#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> sz, ans;

void dfs(int u, int p) {
    sz[u] = 1;
    for(auto v_pair : adj[u]) {
        int v = v_pair.first;
        int c = v_pair.second;
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        ans[u] += min(sz[v], (int)sz.size() - sz[v]) * c + ans[v];
    }
}

int main() {
    int N;
    cin >> N;
    
    adj.resize(N);
    sz.resize(N, 0);
    ans.resize(N, 0);
    
    for(int i = 0; i < N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    dfs(0, -1);
    
    for(int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}