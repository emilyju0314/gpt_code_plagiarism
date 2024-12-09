#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    vector<int> c(n+1);
    vector<int> d(n+1);
    vector<vector<int>> x(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> d[i];
        if (i > 1) {
            int xi;
            cin >> xi;
            x[i].push_back(xi);
        }
    }

    vector<int> dp(n+1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = c[i]; // Cost of buying the item without using any coupons
        for (int j : x[i]) {
            dp[i] = min(dp[i], dp[j] - d[i]); // Update cost using coupon i if needed
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] <= b) {
            result = i; // Update result to keep track of maximum number of goods Karen can buy
        }
    }

    cout << result << endl;

    return 0;
}