#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1)); // dp[i][j] represents the expected number of tosses to determine the winner for i knights with j remaining

    for (int i = 2; i <= n; i++) {
        dp[i][1] = i; // If only one knight remains, we need i tosses to determine the winner
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + 1; // Recurrence relation to calculate the expected number of tosses
        }
    }

    long long numerator = 0, denominator = 0;
    for (int i = 1; i <= n; i++) {
        numerator += dp[n][i];
        denominator += i;
    }

    // Calculate the gcd of numerator and denominator
    long long a = numerator, b = denominator;
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }

    cout << numerator / a << "/" << denominator / a << endl;

    return 0;
}