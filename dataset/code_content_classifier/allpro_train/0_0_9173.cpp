#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int editDistance(const std::string& s1, const std::string& s2) {
    int len1 = s1.size();
    int len2 = s2.size();
    
    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));
    
    for (int i = 1; i <= len1; i++) {
        dp[i][0] = i;
    }
    
    for (int j = 1; j <= len2; j++) {
        dp[0][j] = j;
    }
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + std::min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }
    }
    
    return dp[len1][len2];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> text(n);
    for (int i = 0; i < n; i++) {
        std::cin >> text[i];
    }
    
    std::vector<std::string> dictionary(m);
    for (int i = 0; i < m; i++) {
        std::cin >> dictionary[i];
    }
    
    int minEditDistance = 0;
    
    for (int i = 0; i < n; i++) {
        int minDist = INT_MAX;
        for (const std::string& word : dictionary) {
            int dist = editDistance(text[i], word);
            minDist = std::min(minDist, dist);
        }
        minEditDistance += minDist;
    }
    
    std::cout << minEditDistance << std::endl;
    
    return 0;
}