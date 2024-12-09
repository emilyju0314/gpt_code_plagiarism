#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int L, n;
    cin >> L >> n;

    vector<int> P(n), D(n), T(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i] >> D[i] >> T[i];
    }

    vector<int> dp(L+1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < L; i++) {
        dp[i+1] = min(dp[i+1], dp[i] + 1);

        for (int j = 0; j < n; j++) {
            if (i == P[j]) {
                dp[min(L, i + D[j])] = min(dp[min(L, i + D[j])], dp[i] + T[j]);
            }
        }
    }

    cout << dp[L] << endl;

    return 0;
}