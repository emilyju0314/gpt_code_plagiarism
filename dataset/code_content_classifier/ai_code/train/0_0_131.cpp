#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    string initial;
    cin >> n >> initial;

    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        if (initial[i-1] != initial[i]) {
            dp[i] = 1;
        } else {
            dp[i] = 2;
        }
    }

    for (int i = 2; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum = (sum + dp[j]) % MOD;
        }
        dp[i] = (dp[i] + sum) % MOD;
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        total = (total + dp[i]) % MOD;
    }

    cout << total << endl;

    return 0;
}