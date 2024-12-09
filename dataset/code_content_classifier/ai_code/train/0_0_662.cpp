#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    vector<int> pencils(n);
    for (int i = 0; i < n; i++) {
        cin >> pencils[i];
    }

    sort(pencils.begin(), pencils.end());

    vector<bool> dp(n+1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            if (i - j >= 0 && pencils[i-1] - pencils[i-j] <= d) {
                dp[i] = dp[i] || dp[i-j];
            }
        }
    }

    if (dp[n]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}