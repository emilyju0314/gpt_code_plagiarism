#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

vector<vector<int>> adj;
vector<long long> beauty;
vector<long long> subtreeSum;
long long totalSum = 0;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void dfs(int u, int p) {
    subtreeSum[u] = beauty[u];
    totalSum = (totalSum + beauty[u]) % MOD;

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            long long val = gcd(beauty[u], beauty[v]);
            subtreeSum[u] = (subtreeSum[u] + val * subtreeSum[v] % MOD) % MOD;
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n+1);
    beauty.resize(n+1);
    subtreeSum.resize(n+1);

    for (int i = 1; i <= n; ++i) {
        cin >> beauty[i];
    }

    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    totalSum = 0;
    for (int i = 1; i <= n; ++i) {
        totalSum = (totalSum + subtreeSum[i]) % MOD;
    }

    cout << totalSum << endl;

    return 0;
}