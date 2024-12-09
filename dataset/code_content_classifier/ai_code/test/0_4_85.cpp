#include <iostream>
#include <vector>

using namespace std;

long long power(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;

    while (y > 0) {
        if (y & 1) {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }

    return res;
}

int main() {
    int n;
    long long M;
    cin >> n >> M;

    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));
    dp[1][1] = 1;

    for (int i = 2; i <= n + 1; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i-1][j-1] + j * dp[i-1][j]) % M;
        }
    }

    long long result = 0;
    for (int i = 1; i <= n + 1; i++) {
        result = (result + dp[n + 1][i]) % M;
    }

    cout << result << endl;

    return 0;
}