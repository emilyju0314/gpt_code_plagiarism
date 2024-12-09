#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 998244353;
const int MAX_N = 50001;
const int MAX_M = 1000000001;

int n, m;
long long dp[MAX_N][MAX_M];

long long solve(int idx, int total_difficulty) {
    if (idx == n) {
        return 1;
    }

    if (dp[idx][total_difficulty] != -1) {
        return dp[idx][total_difficulty];
    }

    long long ans = 0;
    for (int i = 0; i + total_difficulty < m; i++) {
        ans = (ans + solve(idx + 1, total_difficulty + i) % MOD) % MOD;
    }

    dp[idx][total_difficulty] = ans;
    return ans;
}

int main() {
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));

    long long result = solve(1, 0);
    cout << result << endl;

    return 0;
}