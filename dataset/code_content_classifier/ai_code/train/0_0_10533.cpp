#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

vector<int> dp(5000001, 0);

int f(int n) {
    if (dp[n] != 0) {
        return dp[n];
    }
    dp[n] = (n % 2 == 0) ? f(n / 2) + n / 2 : f((n + 1) / 2) + n / 2;
    return dp[n] % MOD;
}

int main() {
    int t, l, r;
    cin >> t >> l >> r;

    dp[2] = 1;
    for (int i = 3; i <= 5000000; i++) {
        f(i);
    }

    long long result = 0;
    for (int i = l; i <= r; i++) {
        result = (result + (long long)t * f(i) % MOD) % MOD;
        t = (t * 2) % MOD;
    }

    cout << result << endl;

    return 0;
}