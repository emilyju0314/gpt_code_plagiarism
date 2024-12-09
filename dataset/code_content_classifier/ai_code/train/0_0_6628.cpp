#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> dp(n + 1);
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % MOD;
    }

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = (sum + dp[i]) % MOD;
    }

    cout << sum << endl;

    return 0;
}