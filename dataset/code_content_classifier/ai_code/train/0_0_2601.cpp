#include <iostream>
#include <string>

using namespace std;

int minMovesToEqualStrings(string s, string t) {
    int m = s.length();
    int n = t.length();
    
    // Initialize a 2D array to store the minimum number of moves
    int dp[m + 1][n + 1];
    
    // Dynamic programming approach to find the minimum number of moves
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = i + j;
            }
            else if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    string s, t;
    cin >> s >> t;
    
    int result = minMovesToEqualStrings(s, t);
    
    cout << result << endl;
    
    return 0;
}