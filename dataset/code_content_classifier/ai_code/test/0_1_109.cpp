#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<string> dominoes(n);
    for (int i = 0; i < n; i++) {
        cin >> dominoes[i];
    }

    vector<long long> dp(n+1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        if (dominoes[i-1][0] == '?' && dominoes[i-1][1] == '?') {
            dp[i] = (dp[i-1] * 2 % MOD); // Both cells can be black or white
        } else if (dominoes[i-1][0] == '?' || dominoes[i-1][1] == '?') {
            dp[i] = dp[i-1]; // One cell is already colored
        } else if (dominoes[i-1][0] == dominoes[i-1][1]) {
            dp[i] = 0; // Cells are the same color
        } else {
            dp[i] = dp[i-1]; // Cells are different colors
        }
    }

    cout << dp[n] << endl;

    return 0;
}