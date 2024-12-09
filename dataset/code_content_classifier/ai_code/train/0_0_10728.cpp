#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int minDistance(std::string word1, std::string word2) {
    int m = word1.size();
    int n = word2.size();
    
    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        int d;
        std::cin >> d;
        
        std::vector<std::string> names(n);
        for (int i = 0; i < n; i++) {
            std::cin >> names[i];
        }
        
        std::vector<std::pair<std::string, std::string>> confusingPairs;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (minDistance(names[i], names[j]) <= d) {
                    if (names[i] < names[j]) {
                        confusingPairs.push_back({names[i], names[j]});
                    } else {
                        confusingPairs.push_back({names[j], names[i]});
                    }
                }
            }
        }
        
        std::sort(confusingPairs.begin(), confusingPairs.end());
        
        for (const auto& pair : confusingPairs) {
            std::cout << pair.first << "," << pair.second << std::endl;
        }
        
        std::cout << confusingPairs.size() << std::endl;
    }
    
    return 0;
}