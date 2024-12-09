#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

int countOnes(long long x) {
    int cnt = 0;
    while (x > 0) {
        if (x & 1) cnt++;
        x >>= 1;
    }
    return cnt;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<long long>> dp(k + 1, vector<long long>(3, 0));
    for (int i = 0; i < n; i++) {
        dp[1][countOnes(a[i]) % 3]++;
    }

    for (int i = 2; i <= k; i++) {
        vector<vector<long long>> temp(k + 1, vector<long long>(3, 0));
        for (int j = 0; j <= k; j++) {
            for (int mod = 0; mod < 3; mod++) {
                for (int l = 0; l < n; l++) {
                    temp[j][(mod + countOnes(a[l])) % 3] = (temp[j][(mod + countOnes(a[l])) % 3] + dp[j - 1][mod]) % MOD;
                }
            }
        }
        dp = temp;
    }

    long long ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = (ans + dp[i][0]) % MOD;
    }

    cout << ans << endl;

    return 0;
}