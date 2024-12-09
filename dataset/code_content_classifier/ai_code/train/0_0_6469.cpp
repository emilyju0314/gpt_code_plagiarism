#include <iostream>
#include <vector>
using namespace std;

// Function to calculate power using modulo
long long power(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;
    
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main() {
    int N;
    long long M;
    cin >> N >> M;

    vector<vector<long long>> dp(N+1, vector<long long>(N+1, 0));

    dp[0][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i-1][j-1] + (j * dp[i-1][j]) % M) % M;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = (ans + dp[N][i]) % M;
    }

    cout << ans << endl;

    return 0;
}