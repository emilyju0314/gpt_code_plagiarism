#include <iostream>
#include <vector>
#include <string>

const int MOD = 1000000007;

int countAssignments(const std::string& str1, const std::string& str2, const std::string& str3, int idx, std::vector<std::vector<std::vector<int>>>& dp) {
    if (idx == str1.size()) {
        return 1;
    }

    if (dp[idx][str1[idx] == '?' ? 10 : str1[idx] - '0'][str2[idx] == '?' ? 10 : str2[idx] - '0'] != -1) {
        return dp[idx][str1[idx] == '?' ? 10 : str1[idx] - '0'][str2[idx] == '?' ? 10 : str2[idx] - '0'];
    }

    long long ans = 0;

    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            int carry = i + j;
            if (str1[idx] != '?' && str1[idx] - '0' != i) continue;
            if (str2[idx] != '?' && str2[idx] - '0' != j) continue;
            if (str3[idx] != '?' && str3[idx] - '0' != carry % 10) continue;
            ans = (ans + countAssignments(str1, str2, str3, idx + 1, dp)) % MOD;
        }
    }

    return dp[idx][str1[idx] == '?' ? 10 : str1[idx] - '0'][str2[idx] == '?' ? 10 : str2[idx] - '0'] = ans;
}

int main() {
    std::string str1, str2, str3;
    while (std::cin >> str1 && str1 != "0") {
        std::cin >> str2 >> str3;

        int n = str1.size();

        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(11, std::vector<int>(11, -1)));

        int ans = countAssignments(str1, str2, str3, 0, dp);

        std::cout << ans << std::endl;
    }

    return 0;
}