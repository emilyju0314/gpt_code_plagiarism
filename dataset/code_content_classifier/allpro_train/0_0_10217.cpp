#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 1000000007;

int n, k;
vector<int> lengths;
vector<vector<int>> colors;
vector<vector<int>> edges;
vector<vector<int>> dp;

int dfs(int u, int parent, int parent_color, int mask) {
    if(dp[u][mask] != -1) {
        return dp[u][mask];
    }

    int ways = 1;
    for(int v : edges[u]) {
        if(v != parent) {
            int v_mask = 0;
            for(int i = 0; i < lengths[v]; i++) {
                if(mask & (1 << i)) {
                    v_mask |= (1 << (lengths[u] + i));
                }
            }

            int possible_colors = k;
            if(mask & 1) possible_colors--;
            if(parent != -1 && parent_color == 1) possible_colors--;

            int v_ways = 0;
            for(int c = 0; c < (1 << possible_colors); c++) {
                if(__builtin_popcount(c) > 1) continue;

                int new_mask = (mask >> 1) | v_mask;
                for(int i = 0; i < lengths[v]; i++) {
                    if(c & (1 << i)) {
                        new_mask |= (1 << i);
                    }
                }

                v_ways = (v_ways + dfs(v, u, c & 1, new_mask)) % MOD;
            }

            ways = (1LL * ways * v_ways) % MOD;
        }
    }

    return dp[u][mask] = ways;
}

int main() {
    while(true) {
        cin >> n >> k;
        if(n == 0 && k == 0) break;

        lengths.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> lengths[i];
        }

        edges.assign(n, vector<int>());
        for(int i = 0; i < n-1; i++) {
            int f, p, t, q;
            cin >> f >> p >> t >> q;
            edges[f].push_back(t);
            edges[t].push_back(f);
        }

        dp.assign(n, vector<int>(1 << 30, -1));

        int ans = 0;
        for(int c = 0; c < (1 << k); c++) {
            if(__builtin_popcount(c) > 1) continue;

            ans = (ans + dfs(0, -1, c & 1, c)) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}