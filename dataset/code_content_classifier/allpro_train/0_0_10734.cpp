#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<double> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<double> dp(n+1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1] + 1/p[i-1];
        }

        cout << fixed << setprecision(10) << dp[n] << endl;
    }

    return 0;
}