#include <iostream>
#include <vector>

using namespace std;

int n, m, b, mod;
vector<int> a;
vector<vector<vector<int>>> dp;

int solve(int idx, int lines, int bugs) {
    if (idx == n) {
        if (lines == m && bugs <= b) {
            return 1;
        }
        return 0;
    }

    if (dp[idx][lines][bugs] != -1) {
        return dp[idx][lines][bugs];
    }

    int ans = 0;
    for (int i = 0; i <= m - lines; i++) {
        if (bugs + i * a[idx] <= b) {
            ans = (ans + solve(idx + 1, lines + i, bugs + i * a[idx])) % mod;
        }
    }

    return dp[idx][lines][bugs] = ans;
}

int main() {
    cin >> n >> m >> b >> mod;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp.resize(n, vector<vector<int>>(m + 1, vector<int>(b + 1, -1)));

    int ans = solve(0, 0, 0);
    cout << ans << endl;

    return 0;
}