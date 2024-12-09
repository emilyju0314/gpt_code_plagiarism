#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;

    std::vector<int> a(26);
    for (int i = 0; i < 26; ++i) {
        std::cin >> a[i];
    }
    
    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        int max_len = 0;
        int min_count = 0;
        for (int j = i - 1; j >= 0; --j) {
            int char_idx = s[j] - 'a';
            max_len = std::max(max_len, i - j);
            if (max_len > a[char_idx]) {
                break;
            } else {
                min_count = std::max(min_count, 1 + dp[j]);
            }
        }
        dp[i] = min_count;
    }

    int total_ways = dp[n] - 1; // subtract 1 because we don't want the empty string
    int max_length = *std::max_element(dp.begin(), dp.end()) - 1;
    int min_substrings = dp[n];

    std::cout << total_ways << std::endl;
    std::cout << max_length << std::endl;
    std::cout << min_substrings << std::endl;

    return 0;
}