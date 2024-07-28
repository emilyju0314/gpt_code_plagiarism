#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int dp[31] = {0};
        dp[0] = dp[1] = dp[2] = 0;
        dp[3] = 1;

        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        int total = 1;
        for (int i = 0; i < n; i++) {
            total += dp[i];
        }

        cout << total << endl;
    }

    return 0;
}
