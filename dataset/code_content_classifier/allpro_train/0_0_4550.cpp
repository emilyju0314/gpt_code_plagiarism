#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> incomes(n);
    for (int i = 0; i < n; i++) {
        cin >> incomes[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        dp[i][i] = incomes[i];
    }
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = max(incomes[i] - dp[i + 1][j], incomes[j] - dp[i][j - 1]);
        }
    }
    
    cout << dp[0][n-1] << endl;
    
    return 0;
}