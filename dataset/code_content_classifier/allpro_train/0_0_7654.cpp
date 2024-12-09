#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int n;
string row1, row2, row3;
int dp[10003][3][3][3][3];

int solve(int idx, int prev1, int prev2, int next1, int next2) {
    if (idx == n) {
        if ((prev1 || prev2) && (next1 || next2)) {
            return 1;
        }
        return 0;
    }

    if (dp[idx][prev1][prev2][next1][next2] != -1) {
        return dp[idx][prev1][prev2][next1][next2];
    }

    int ans = 0;

    if (row2[idx] == '.' && row2[idx] == 'O') {
        if (!prev1 && !prev2) {
            ans = (ans + solve(idx+1, 0, 0, next1, next2)) % MOD;
        }
    }

    if (row1[idx] == '.' && row2[idx] == '.') {
        ans = (ans + solve(idx+1, 0, prev1, 0, next1)) % MOD;
    }

    if (row2[idx] == '.' && row3[idx] == '.') {
        ans = (ans + solve(idx+1, prev2, 0, next2, 0)) % MOD;
    }

    if (row1[idx] == '.' && row2[idx] == '.' && row3[idx] == '.') {
        ans = (ans + solve(idx+1, 0, prev1, next1, next2)) % MOD;
    }

    return dp[idx][prev1][prev2][next1][next2] = ans;
}

int main() {
    cin >> n;
    cin >> row1 >> row2 >> row3;

    memset(dp, -1, sizeof(dp));

    int ans = solve(0, 0, 0, 0, 0);
    cout << ans << endl;

    return 0;
}