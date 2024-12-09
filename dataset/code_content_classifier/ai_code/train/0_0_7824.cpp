#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    cin >> m;

    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= 2*n; i++) {
        for (int j = min(n, i); j >= 1; j--) {
            for (int k = 0; k < n; k++) {
                if (a[j-1] <= b[k]) {
                    dp[j] = (dp[j] + dp[j-1]) % MOD;
                }
            }
        }
    }

    cout << dp[n] % m << endl;

    return 0;
}