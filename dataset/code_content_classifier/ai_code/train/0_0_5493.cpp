#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> dp;

int countOnes(int u) {
    return __builtin_popcount(u);
}

int main() {
    int m, n, p;
    cin >> m >> n >> p;

    int vertices = pow(2, m);

    vector<int> e0(vertices);
    for (int i = 0; i < vertices; i++) {
        cin >> e0[i];
    }

    vector<int> b(m + 1);
    for (int i = 0; i <= m; i++) {
        cin >> b[i];
    }

    dp.resize(vertices, vector<int>(vertices));

    for (int i = 0; i < vertices; i++) {
        dp[0][i] = e0[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int u = 0; u < vertices; u++) {
            for (int v = 0; v < vertices; v++) {
                dp[i][u] = (dp[i][u] + dp[i-1][v] * pow(b[countOnes(u ^ v)], p)) % p;
            }
        }
    }

    for (int i = 0; i < vertices; i++) {
        cout << dp[n][i] << endl;
    }

    return 0;
}