#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

int dfs(vector<vector<int>> const& g, int v, int inv_num, vector<int>& invited) {
    const int N = g.size();
    int res = 0;
    if(inv_num == 0) {
        for(auto i : invited) {
            int t = INF;
            for(auto j : invited) {
                if(i == j) {
                    continue;
                }
                t = min(t, g[i][j]);
            }
            res += t;
        }
        return res == INF ? 0 : res;
    }
    if(v == N) {
        return 0;
    }
    for(auto u : invited) {
        if(g[v][u] == 0) {
            return dfs(g, v+1, inv_num, invited);
        }
    }
    invited.push_back(v);
    res = max(res, dfs(g, v+1, inv_num-1, invited));
    invited.pop_back();
    res = max(res, dfs(g, v+1, inv_num, invited));
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i=0; i<m; ++i) {
        int u, v, f;
        cin >> u >> v >> f;
        u--; v--;
        g[u][v] = g[v][u] = f;
    }
    int res = 0;
    for(int i=0; i*(i-1)/2 <= m; ++i) {
        vector<int> invited;
        res = max(res, dfs(g, 0, i, invited));
    }
    cout << res << endl;
}
