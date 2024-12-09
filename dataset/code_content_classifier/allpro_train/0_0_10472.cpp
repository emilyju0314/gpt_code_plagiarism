#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    vector<vector<double>> dp(1002, vector<double>(502, 0.0));
    
    for (int i = 2; i <= 1000; i += 2) {
        dp[i][1] = 0.0;
        
        for (int j = 2; j <= i/2; j++) {
            dp[i][j] = (i - j) * j / (double)(i * (i - 1)) + (2 * j * (i - j) / (double)(i * (i - 1))) * (dp[i - 1][j + 1] + 1);
        }
    }
    
    int n;
    while (cin >> n && n != 0) {
        cout << fixed << setprecision(10) << dp[n][2] << endl;
    }
    
    return 0;
}