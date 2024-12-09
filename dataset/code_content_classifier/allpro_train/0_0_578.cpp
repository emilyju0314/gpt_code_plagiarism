#include <iostream>
#include <vector>

using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int N, M, K;
    long long D;
    cin >> N >> M >> K >> D;

    vector<vector<long long>> dp(N+1, vector<long long>(M+1, 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = power(K, (i*j), D);
        }
    }

    long long result = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            long long min_val = min(i, N-i+1)*min(j, M-j+1);
            result = (result + dp[i][j] * min_val % D) % D;
        }
    }

    cout << result << endl;

    return 0;
}