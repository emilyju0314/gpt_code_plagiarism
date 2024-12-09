#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;
        
        vector<int> D(N);
        vector<int> P(N);
        for (int i = 0; i < N; i++) {
            cin >> D[i] >> P[i];
        }
        
        vector<double> dp(N, INT_MAX);
        dp[0] = P[0];
        
        for (int i = 1; i < N; i++) {
            dp[i] = min(dp[i], dp[i-1] + (double)P[i]);
            
            for (int j = i-1; j >= 0; j--) {
                int distance = 0;
                for (int k = j; k < i; k++) {
                    distance += D[k];
                }
                
                double cost = (double)distance * P[i];
                if (cost <= M) {
                    dp[i] = min(dp[i], dp[j] + (double)P[i]);
                }
            }
        }
        
        cout << fixed << setprecision(0) << dp[N-1] << endl;
    }
    
    return 0;
}