#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    int k;
    std::cin >> s;
    std::cin >> k;

    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (len == 1) {
                dp[i][j] = 0;
            } else if (len == 2) {
                dp[i][j] = (s[i] != s[j]) ? 1 : 0;
            } else {
                dp[i][j] = dp[i + 1][j - 1] + ((s[i] != s[j]) ? 1 : 0);
            }
        }
    }

    std::vector<std::string> palindromes;
    std::vector<int> palin_ends;
    int changes = dp[0][n - 1];
    if (changes <= k) {
        palindromes.push_back(s);
    } else {
        for (int i = 1; i < n; i++) {
            if (dp[0][i-1] <= k - 1 && dp[i][n-1] <= k - 1) {
                palindromes.push_back(s.substr(0, i));
                palindromes.push_back(s.substr(i));
                changes = dp[0][i-1] + dp[i][n-1];
                break;
            }
        }
    }

    std::cout << changes << std::endl;
    for (int i = 0; i < palindromes.size(); i++) {
        std::cout << palindromes[i];
        if (i < palindromes.size() - 1) {
            std::cout << "+";
        }
    }
    std::cout << std::endl;

    return 0;
}