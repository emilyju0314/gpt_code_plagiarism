#include <iostream>
#include <string>
#include <vector>

std::string longestRepeatingSubsequence(std::string str) {
    int n = str.length();
    int **dp = new int*[n+1];
    for (int i = 0; i < n+1; i++) {
        dp[i] = new int[n+1];
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (str[i-1] == str[j-1] && i != j) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int index = dp[n][n];
    char lrs[index+1];
    lrs[index] = '\0';
    
    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i-1][j-1] + 1) {
            lrs[index-1] = str[i-1];
            i--;
            j--;
            index--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    
    std::string result = lrs;
    
    for (int i = 0; i <= n; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    
    return result;
}

int main() {
    std::string str;
    
    while (std::getline(std::cin, str)) {
        if (str == "#END") {
            break;
        }
        
        std::string result = longestRepeatingSubsequence(str);
        std::cout << result << std::endl;
    }
    
    return 0;
}