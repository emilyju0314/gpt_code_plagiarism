#include <iostream>
#include <vector>
#include <bitset>

#define MOD 1000000007
using namespace std;

int n, m;
vector<pair<int, int>> adj[100005];
bitset<32> xor_vals[100005];

int dfs(int v, int p) {
    int ans = 1;
    for (auto u : adj[v]) {
        if (u.first == p) continue;
        ans &= dfs(u.first, v);
        xor_vals[v] ^= (xor_vals[u.first] ^ (1 << u.second));
    }
    return ans && ((xor_vals[v].count() == 1 && xor_vals[v][0]) || (xor_vals[v].count() == 0));
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dfs(0, -1);

    int count = 0;
    for (int i = 0; i < 32; i++) {
        bool valid = true;
        for (auto u : adj[0]) {
            valid &= ((xor_vals[u.first][i]) == 0);
        }
        count += valid;
    }

    cout << (1 << count) % MOD << endl;
    
    return 0;
}