#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<double> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    
    vector<vector<double>> dp(N+1, vector<double>(N+1, 0.0));
    dp[0][0] = 1.0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i+1][j+1] += dp[i][j] * p[i];
            dp[i+1][j] += dp[i][j] * (1 - p[i]);
        }
    }
    
    double ans = 0.0;
    for (int i = (N+1)/2; i <= N; i++) {
        ans += dp[N][i];
    }
    
    cout << fixed << setprecision(10) << ans << endl;
    
    return 0;
}