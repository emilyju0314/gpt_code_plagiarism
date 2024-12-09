#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 924844033;

vector<vector<int>> adj;
vector<int> size;

void dfs(int u, int parent) {
    size[u] = 1;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            size[u] += size[v];
        }
    }
}

int main() {
    int N;
    cin >> N;

    adj.resize(N + 1);
    size.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    vector<int> result(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        long long ans = 0;
        for (int j = 1; j <= N; j++) {
            ans = (ans + (long long)size[j] * (size[j] - 1) / 2 % MOD) % MOD;
        }
        cout << ans << "\n";

        for (int j = 1; j <= N; j++) {
            for (int v : adj[j]) {
                size[j] = 1;
            }
        }
    }

    return 0;
}