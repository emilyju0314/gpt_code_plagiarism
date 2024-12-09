#include <iostream>
#include <vector>

std::string longestCommonSubsequence(std::string s1, std::string s2) {
    int m = s1.length();
    int n = s2.length();
    
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    std::string lcs = "";
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;
            i--; j--;
        } else if(dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    return lcs;
}

int main() {
    std::string s1, s2, virus;
    std::cin >> s1 >> s2 >> virus;
    
    std::string lcs = longestCommonSubsequence(s1, s2);
    
    if(lcs.find(virus) != std::string::npos) {
        size_t pos = lcs.find(virus);
        lcs.erase(pos, virus.length());
    }
    
    if(lcs.empty()) {
        std::cout << "0\n";
    } else {
        std::cout << lcs << "\n";
    }
    
    return 0;
}