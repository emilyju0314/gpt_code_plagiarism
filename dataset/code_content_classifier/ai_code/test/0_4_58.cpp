#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int i, int j, vector<vector<char>>& level) {
    int n = level[0].size();
    if (i < 0 || j < 0 || i >= 2 || j >= n) {
        return false;
    }
    if (level[i][j] == '1') {
        return false;
    }
    return true;
}

bool canCompleteLevel(vector<vector<char>>& level) {
    int n = level[0].size();
    bool dp[2][n];
    
    dp[0][0] = true;
    
    for (int j = 1; j < n; j++) {
        dp[0][j] = isSafe(0, j, level) && dp[0][j-1];
    }
    
    dp[1][0] = false;
    
    for (int j = 1; j < n; j++) {
        dp[1][j] = isSafe(1, j, level) && (dp[0][j-1] || dp[1][j-1] || (j > 1 && dp[0][j-2]));
    }
    
    return dp[1][n - 1];
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<char>> level(2, vector<char>(n));
        
        for (int i = 0; i < 2; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < n; j++) {
                level[i][j] = row[j];
            }
        }
        
        if (canCompleteLevel(level)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}