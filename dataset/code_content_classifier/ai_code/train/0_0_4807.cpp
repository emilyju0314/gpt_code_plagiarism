#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int m, d;
    std::cin >> m >> d;
    
    std::string a_str, b_str;
    std::cin >> a_str >> b_str;
    
    int a_len = a_str.size();
    int b_len = b_str.size();
    
    std::vector<std::vector<std::vector<int>>> dp(b_len + 1, std::vector<std::vector<int>>(m, std::vector<int>(2, 0)));
    dp[0][0][0] = 1;
    
    for (int len = 1; len <= b_len; ++len) {
        for (int mod = 0; mod < m; ++mod) {
            for (int tight = 0; tight < 2; ++tight) {
                for (int digit = 0; digit <= (tight ? b_str[len - 1] - '0' : 9); ++digit) {
                    if (len % 2 == 1 && digit == d) continue;
                    int new_mod = (mod * 10 + digit) % m;
                    int new_tight = tight && (digit == b_str[len - 1] - '0');
                    dp[len][new_mod][new_tight] += dp[len - 1][mod][tight];
                    dp[len][new_mod][new_tight] %= MOD;
                }
            }
        }
    }
    
    int ans_b = 0;
    for (int mod = 0; mod < m; ++mod) {
        if (mod == 0) continue;
        int cnt_b = 0;
        
        for (int tight = 0; tight < 2; ++tight) {
            cnt_b += dp[b_len][mod][tight];
            cnt_b %= MOD;
        }
        
        int cnt_a = 0;
        if (a_len != 1) {
            for (int tight = 0; tight < 2; ++tight) {
                cnt_a += dp[a_len - 1][mod][tight];
                cnt_a %= MOD;
            }
        }
        
        ans_b += (MOD + cnt_b - cnt_a) % MOD;
        ans_b %= MOD;
    }
    
    int ans_a = 0;
    
    std::fill(dp.begin(), dp.end(), std::vector<std::vector<int>>(m, std::vector<int>(2, 0)));
    dp[0][0][0] = 1;
    
    for (int len = 1; len < a_len; ++len) {
        for (int mod = 0; mod < m; ++mod) {
            for (int tight = 0; tight < 2; ++tight) {
                for (int digit = 0; digit <= (tight ? a_str[len - 1] - '0' : 9); ++digit) {
                    if (len % 2 == 1 && digit == d) continue;
                    int new_mod = (mod * 10 + digit) % m;
                    int new_tight = tight && (digit == a_str[len - 1] - '0');
                    dp[len][new_mod][new_tight] += dp[len - 1][mod][tight];
                    dp[len][new_mod][new_tight] %= MOD;
                }
            }
        }
    }
    
    for (int mod = 0; mod < m; ++mod) {
        if (mod == 0) continue;
        for (int tight = 0; tight < 2; ++tight) {
            ans_a += dp[a_len - 1][mod][tight];
            ans_a %= MOD;
        }
    }
    
    int ans = (ans_b + ans_a) % MOD;
    std::cout << ans << std::endl;
    
    return 0;
}