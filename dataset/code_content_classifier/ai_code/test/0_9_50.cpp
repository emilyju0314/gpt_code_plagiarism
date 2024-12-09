#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> dp(n);
    dp[0] = a[0];

    for(int i = 1; i < n; i++) {
        dp[i] = (dp[i-1] + ((long long)a[i] - 1) * dp[i-1]) % MOD;
    }

    cout << dp[n-1] << endl;

    return 0;
}