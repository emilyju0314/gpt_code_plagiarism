#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<double> dp(1 << n, 1e9); // Initialize dp array with a large number
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                int new_mask = mask | (1 << i);
                double cost = min((double)c[i], x/2.0) + dp[mask];
                dp[new_mask] = min(dp[new_mask], cost);
            }
        }
    }

    cout << fixed << setprecision(9) << dp[(1 << n) - 1] << endl;

    return 0;
}