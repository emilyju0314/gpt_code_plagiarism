#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<double> probabilities(x+1);
    
    for(int i = 0; i <= x; i++) {
        cin >> probabilities[i];
    }
    
    vector<double> dp(x+1);
    dp[0] = 0;
    
    for(int i = 1; i <= x; i++) {
        double temp = 0;
        for(int j = 0; j < i; j++) {
            temp += probabilities[j];
        }
        dp[i] = temp;
    }
    
    for(int i = 1; i < n; i++) {
        vector<double> new_dp(x+1);
        
        for(int j = 0; j <= x; j++) {
            for(int k = 1; k <= x; k++) {
                if(j >= k) {
                    new_dp[j] += dp[j-k] * probabilities[k];
                } else {
                    new_dp[j] += dp[k-j] * probabilities[k];
                }
            }
        }
        
        dp = new_dp;
    }
    
    double result = 0;
    for(int i = 1; i <= x; i++) {
        result += dp[i];
    }
    
    cout << fixed << setprecision(6) << result << endl;
    
    return 0;
}