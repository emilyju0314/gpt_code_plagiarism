#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 998244353
using namespace std;

long long power(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % p;
        }
        x = (x * x) % p;
        y = y / 2;
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> freq(n + 2, 0);
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        int mex = 0;
        while (freq[mex] > 0) mex++;

        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            dp[i + 1] = (2 * dp[i]) % MOD;
            if (a[i] < mex) {
                dp[i + 1] = (dp[i + 1] + dp[freq[a[i]]]) % MOD;
            }
            freq[a[i]]--;
            if (freq[a[i]] == 0 && a[i] == mex) {
                mex++;
                while (freq[mex] > 0) mex++;
            }
        }

        cout << (dp[n] - 1 + MOD) % MOD << endl;
    }

    return 0;
}