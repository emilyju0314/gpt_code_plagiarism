#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<long long> dp(n+1, 0);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[p[i-1]] + 2) % MOD;
    }

    cout << dp[n] << endl;

    return 0;
}