#include <iostream>
#include <string>
#include <vector>

std::string decryptMessage(const std::string& encrypted) {
    int n = encrypted.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            if (encrypted[i] == encrypted[j] && len == 2) {
                dp[i][j] = 2;
            } else if (encrypted[i] == encrypted[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    std::string decrypted;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (encrypted[i] == encrypted[j]) {
            decrypted.push_back(encrypted[i]);
            if (i != j) {
                decrypted.insert(decrypted.begin(), encrypted[j]);
            }
            i++;
            j--;
        } else if (dp[i+1][j] > dp[i][j-1]) {
            i++;
        } else {
            j--;
        }
    }

    return decrypted;
}

int main() {
    std::string encrypted;
    
    while (std::cin >> encrypted) {
        std::string decrypted = decryptMessage(encrypted);
        std::cout << decrypted << std::endl;
    }

    return 0;
}