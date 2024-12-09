#include <iostream>
#include <string>
#include <algorithm>

int longestCommonSubstring(std::string s1, std::string s2) {
    int n = s1.length();
    int m = s2.length();

    int dp[n+1][m+1];
    int result = 0;

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                result = std::max(result, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return result;
}

int main() {
    std::string s1, s2;
    
    while(std::cin >> s1 >> s2) {
        int maxLength = longestCommonSubstring(s1, s2);
        std::cout << maxLength << std::endl;
    }

    return 0;
}