#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> incomes(n);
    for(int i = 0; i < n; i++){
        cin >> incomes[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j <= n-i; j++){
            dp[i][j] = max(incomes[i] + dp[i+1][j-1], dp[i+1][j]);
        }
    }
    
    cout << dp[0][n] << endl;
    
    return 0;
}