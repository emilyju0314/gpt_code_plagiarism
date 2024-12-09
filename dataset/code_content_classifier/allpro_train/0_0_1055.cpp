#include <iostream>
#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long dp1[m+1], dp2[m+1];
    dp1[1] = m;
    dp2[1] = 0;

    for (int i = 2; i <= m; i++) {
        dp1[i] = ((dp1[i-1] + dp2[i-1]) % MOD) * (m-1) % MOD;
        dp2[i] = dp1[i-1];
    }

    long long ans = (dp1[m] + dp2[m]) % MOD;
    cout << ans << endl;

    return 0;
}