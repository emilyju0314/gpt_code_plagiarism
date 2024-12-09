#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    vector<int> freq(c + 1, 0);
    dp[0][0] = 1;

    long long total = 1;
    for(int i = 0; i < n; i++) {
        total = (total * 2) % MOD;
        freq[a[i]]++;

        long long sum = 0, sum_freq = 0;
        vector<long long> temp(n + 1, 0);
        for(int j = 0; j <= i; j++) {
            sum = (sum + dp[i][j]) % MOD;
            if(freq[a[i]] == 1) {
                sum_freq = (sum_freq + dp[i][j]) % MOD;
            }
        }

        for(int j = 0; j <= i; j++) {
            temp[j] = (dp[i][j] * total - sum) % MOD;
        }

        for(int j = 0; j <= i; j++) {
            dp[i + 1][j] = temp[j];
        }

        if(freq[a[i]] == 1) {
            for(int j = 0; j <= i; j++) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + sum_freq) % MOD;
            }
        }
    }

    for(int p = 0; p <= n; p++) {
        long long ans = 0;
        for(int k = 0; k <= n; k++) {
            ans = (ans + dp[k][p]) % MOD;
        }
        cout << ans << " ";
    }

    return 0;
}