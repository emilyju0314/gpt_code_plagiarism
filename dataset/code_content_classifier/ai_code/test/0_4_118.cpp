#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int MAXN = 250005;

vector<int> adj[MAXN];
vector<int> dp1(MAXN);
vector<int> dp2(MAXN);

void dfs(int u, int p) {
    dp1[u] = 1;
    dp2[u] = 1;

    for (int v : adj[u]) {
        if (v == p) continue;
        
        dfs(v, u);
        
        dp1[u] = (1LL * dp1[u] * (dp1[v] + dp2[v])) % MOD;
        dp2[u] = (1LL * dp2[u] * dp1[v]) % MOD;
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    int ans = (dp1[1] + dp2[1]) % MOD;
    cout << ans << endl;

    return 0;
}