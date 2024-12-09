#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    long long ans = 0;
    for (char col1 : {'B', 'W'}) {
        vector<long long> dp1(n+1), dp2(n+1);
        dp1[0] = 1;

        for (int i = 1; i <= n; i++) {
            if (s[i-1] != col1 && s[i-1] != 'X') {
                dp1[i] = 0;
            } else {
                dp1[i] = (dp1[i-1] + dp2[i-1]) % MOD;
            }
            if (i >= k) dp2[i] = dp1[i-k];
        }

        for (int i = n-k+1; i <= n; i++) {
            if (s[i-1] != col1 && s[i-1] != 'X') {
                dp2[i] = 0;
            } else {
                dp2[i] = (dp1[i-1] + dp2[i-1]) % MOD;
            }
        }

        for (int i = k; i <= n; i++) ans = (ans + dp2[i]) % MOD;
    }
    cout << ans << endl;

    return 0;
}