#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n);
    dp[0] = a[0];
    for(int i = 1; i < n; i++) {
        dp[i] = ((1LL*dp[i-1]*2) + a[i]) % MOD;
    }

    long long ans = dp[n-1];
    for(int i = 0; i < n-1; i++) {
        ans = (ans + a[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}