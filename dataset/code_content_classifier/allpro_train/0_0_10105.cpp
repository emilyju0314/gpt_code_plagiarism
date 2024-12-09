#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
vector<string> connectivityMatrix;
vector<vector<int>> dp;

int solve(int mask, int node) {
    if (dp[mask][node] != -1) {
        return dp[mask][node];
    }

    if (mask == ((1 << n) - 1)) {
        return dp[mask][node] = 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (connectivityMatrix[node][i] == 'A' && (mask & (1 << i)) == 0) {
            if (solve(mask | (1 << i), i)) {
                ans = 1;
                break;
            }
        } else if (connectivityMatrix[node][i] == 'O' && (mask & (1 << i)) == 0) {
            ans = 1;
            break;
        } else if (connectivityMatrix[node][i] == 'X' && (mask & (1 << i)) == 0) {
            if (!solve(mask | (1 << i), i)) {
                ans = 1;
                break;
            }
        }
    }

    return dp[mask][node] = ans;
}

int main() {
    cin >> n;
    connectivityMatrix.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> connectivityMatrix[i];
    }

    dp.assign(1 << n, vector<int>(n, -1));

    int ans = n;
    for (int i = 0; i < n; i++) {
        if (solve(1 << i, i)) {
            ans = min(ans, __builtin_popcount(dp[1 << i][i]));
        }
    }

    if (ans == n) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}