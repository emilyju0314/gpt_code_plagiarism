#include <iostream>
using namespace std;

long long powerOfDevil(int N, int K) {
    long long dp[101][101] = {0};
    dp[0][1] = 1;
    
    for (int k = 2; k <= K; k++) {
        for (int n = 1; n <= N; n++) {
            for (int d = 1; d <= N/n; d++) {
                if (dp[k-1][d]) {
                    dp[k][n*d] += dp[k-1][d];
                }
            }
        }
    }
    
    long long result = 0;
    for (int n = 1; n <= N; n++) {
        result += dp[K][n];
    }
    
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    cout << powerOfDevil(N, K) << endl;
    
    return 0;
}