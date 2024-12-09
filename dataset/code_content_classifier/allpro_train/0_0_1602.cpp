#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> p(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    vector<vector<double>> dp(n+1, vector<double>(k+1, 0.0));
    
    vector<double> inversions(n+1, 0.0);
    for(int i = 1; i <= n; i++) {
        inversions[i] = inversions[i-1];
        for(int j = i-1; j >= 1; j--) {
            if(p[j] > p[i]) {
                inversions[i]++;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        dp[i][0] = inversions[i];
    }
    
    for(int j = 1; j <= k; j++) {
        for(int i = 1; i <= n; i++) {
            for(int l = 1; l < i; l++) {
                for(int r = i; r <= n; r++) {
                    dp[i][j] += (1.0 / (n*(n+1)/2)) * ((r-i+1) * (l-1) * dp[l-1][j-1] + (n-r) * (n-l) * (inversions[n]-inversions[r]));
                }
            }
        }
    }
    
    double ans = 0.0;
    for(int i = 1; i <= n; i++) {
        ans += dp[i][k];
    }
    
    cout << fixed << setprecision(9) << ans << "\n";
    
    return 0;
}