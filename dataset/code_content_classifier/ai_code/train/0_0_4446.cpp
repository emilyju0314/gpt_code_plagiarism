#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// Function to calculate binomial coefficient C(n, k)
int binomial(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return (binomial(n-1, k-1) + binomial(n-1, k)) % MOD;
}

int main() {
    int n, k;
    long long m;
    cin >> n >> m >> k;
    
    vector<vector<int>> dp(n+1, vector<int>(n*n+1, 0));
    
    // Calculate the number of ways to place k points in an n x n square
    for (int i = 0; i < n+1; i++) {
        dp[i][0] = 1;
        for (int j = 1; j < n*n+1; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
        }
    }
    
    // Calculate the number of ways to fill the table with points
    long long total_ways = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m % n == 0) {
                total_ways = (total_ways * dp[n][k]) % MOD;
            } else {
                total_ways = (total_ways * binomial(n, k)) % MOD;
            }
        }
    }
    
    cout << total_ways << endl;
    
    return 0;
}