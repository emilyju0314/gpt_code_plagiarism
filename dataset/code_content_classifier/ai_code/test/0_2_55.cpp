#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int k;
vector<vector<long long>> dp;

long long solve(int node, int color) {
    if (dp[node][color] != -1) {
        return dp[node][color];
    }

    long long ans = 1;
    if (node < (1 << (k - 1))) {
        for (int i = 0; i < 6; i++) {
            if (i != color) {
                ans = (ans * solve(2 * node, i)) % MOD;
            }
        }
        ans = (ans * solve(2 * node, color)) % MOD;
        ans = (ans * solve(2 * node + 1, color)) % MOD;
    }

    dp[node][color] = ans;
    return ans;
}

int main() {
    cin >> k;
    dp.resize(1 << k, vector<long long>(6, -1));

    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < 6; j++) {
            dp[i][j] = 1;
        }
    }

    long long ans = 0;
    for (int i = 0; i < 6; i++) {
        ans = (ans + solve(1, i)) % MOD;
    }

    cout << ans << endl;

    return 0;
}