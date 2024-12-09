#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

long long power(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> extraEdges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        extraEdges.push_back({u, v});
    }

    long long ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        ans = (ans + (2 * (n - i) + 1) * i) % MOD;
    }

    for (auto& edge : extraEdges) {
        int u = edge.first, v = edge.second;
        int x = min(u, v) - 1, y = n - max(u, v);
        ans = (ans + (2 * (x + y) + 1)) % MOD;
    }

    cout << ans << endl;

    return 0;
}