#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int binomialCoefficient(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
        }
    }
    return dp[n][k];
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; i++) {
        int li, ri, ki;
        cin >> li >> ri >> ki;
        for (int j = li-1; j < ri; j++) {
            a[j] = (a[j] + binomialCoefficient(ri-li, j-li) * ki) % MOD;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}