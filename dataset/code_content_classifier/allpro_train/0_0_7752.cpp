#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    string digits;
    cin >> n >> digits;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        int num = 0;
        for (int j = i; j >= 1; j--) {
            int digit = digits[j-1] - '0';
            if (digit == 0)
                break;
            num = num + digit * pow(10, i - j);
            if (num > i)
                break;
            dp[i] = (dp[i] + dp[j-1]) % MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}