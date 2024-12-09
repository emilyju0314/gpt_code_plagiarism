#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

vector<vector<int>> adj;
vector<long long> dp_white, dp_black;

void dfs(int u, int parent) {
    dp_white[u] = dp_black[u] = 1;

    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);

        dp_white[u] = (dp_white[u] * (dp_white[v] + dp_black[v])) % MOD;
        dp_black[u] = (dp_black[u] * dp_white[v]) % MOD;
    }
}

int main() {
    int N;
    cin >> N;

    adj.resize(N);
    dp_white.resize(N);
    dp_black.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, -1);

    cout << (dp_white[0] + dp_black[0]) % MOD << endl;

    return 0;
}