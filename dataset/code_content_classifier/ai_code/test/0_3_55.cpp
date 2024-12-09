#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int k;
    cin >> k;

    // Calculate the total number of nodes in the binary tree
    long long totalNodes = (1LL << k) - 1;

    // Calculate the number of colorings for each node
    vector<long long> dp(k + 1);
    dp[0] = 1;
    dp[1] = 6;

    for (int i = 2; i <= k; i++) {
        dp[i] = (dp[i - 1] * power(6, (1LL << (i - 1)) % (MOD - 1))) % MOD;
    }

    // Calculate the total number of good colorings of the binary tree
    long long result = power(dp[1], totalNodes);

    cout << result << endl;

    return 0;
}