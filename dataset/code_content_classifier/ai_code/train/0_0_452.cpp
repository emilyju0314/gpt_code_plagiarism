#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

const int MOD = 998244353;

int n, m;
std::vector<std::string> words;
std::unordered_map<int, int> dp[2][1<<8][1<<8];

int count(int idx, int first_mask, int second_mask, bool is_first_hint) {
    if(idx == m) {
        return 1;
    }

    if(dp[is_first_hint][first_mask][second_mask].find(idx) != dp[is_first_hint][first_mask][second_mask].end()) {
        return dp[is_first_hint][first_mask][second_mask][idx];
    }

    int res = 0;

    for(int i = 0; i < n; i++) {
        int new_first_mask = (first_mask << 1) | 1;
        int new_second_mask = (second_mask >> 1) | (1 << (n - 1));

        if(is_first_hint && (new_first_mask & 1) == 1) {
            if(words[i].size() + idx <= m) {
                bool valid = true;
                for(int j = 0; j < words[i].size(); j++) {
                    if(((first_mask >> j) & 1) == 1 && words[i][j] != words[i][j + idx]) {
                        valid = false;
                        break;
                    }
                    new_first_mask |= 1 << (j + idx);
                }

                if(valid) {
                    res = (res + count(idx + words[i].size(), new_first_mask, second_mask, true)) % MOD;
                }
            }
        } else if(!is_first_hint && (new_second_mask & (1 << (n - 1))) == 1) {
            if(words[i].size() + idx <= m) {
                bool valid = true;
                for(int j = 0; j < words[i].size(); j++) {
                    if(((second_mask >> (n - 1 - j)) & 1) == 1 && words[i][j] != words[i][words[i].size() - 1 - j - idx]) {
                        valid = false;
                        break;
                    }
                    new_second_mask = new_second_mask & ~(1 << (n - 1 - j));
                }

                if(valid) {
                    res = (res + count(idx + words[i].size(), first_mask, new_second_mask, false)) % MOD;
                }
            }
        }
    }

    dp[is_first_hint][first_mask][second_mask][idx] = res;
    return res;
}

int main() {
    std::cin >> n >> m;

    for(int i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        words.push_back(word);
    }

    int ans = count(0, 0, 0, true) + count(0, 0, 0, false);
    std::cout << ans % MOD << std::endl;

    return 0;
}