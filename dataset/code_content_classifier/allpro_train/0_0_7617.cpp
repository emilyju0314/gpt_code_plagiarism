#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

double expectedValue(int N, int M, vector<vector<double>>& dp) {
    if(N == 1) {
        return 3.5;
    }
    
    if(M == 0) {
        return 0.0;
    }
    
    if(dp[N][M] > 0) {
        return dp[N][M];
    }
    
    double score = 0;
    for(int i = 1; i <= 6; i++) {
        score += expectedValue(N-1, M-1, dp) + i;
    }
    
    dp[N][M] = score / 6.0;
    
    return dp[N][M];
}

int main() {
    int N, M;
    
    while(true) {
        cin >> N >> M;
        
        if(N == 0 && M == 0) {
            break;
        }
        
        vector<vector<double>> dp(N+1, vector<double>(M+1, 0.0));
        
        cout << fixed << setprecision(10) << expectedValue(N, M, dp) << endl;
    }
    
    return 0;
}