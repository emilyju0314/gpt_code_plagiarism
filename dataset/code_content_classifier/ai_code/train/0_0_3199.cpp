#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isGood(int num) {
    while (num > 0) {
        if (num % 10 != 2 && num % 10 != 8) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    long long n;
    cin >> n;

    vector<int> dp(n+1, -1);
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i/2; j++) {
            if (dp[j] != -1 && dp[i-j] != -1) {
                dp[i] = max(dp[i], dp[j] + dp[i-j]);
            }
        }
        if (isGood(i)) {
            dp[i] = max(dp[i], 1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}