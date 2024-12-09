#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n, k;
        long long x;
        std::cin >> n >> k >> x;
        
        std::string s;
        std::cin >> s;
        
        std::vector<long long> dp(n + 1);
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            if(s[i-1] == '*') {
                for(int j = std::min(i, k); j >= 1; j--) {
                    dp[j] += dp[j-1];
                }
            }
        }
        
        std::string ans = "";
        int remaining = x;
        for(int i = n; i >= 1; i--) {
            if(s[i-1] == '*') {
                long long skip = 0;
                for(int j = std::min(i, k); j >= 1; j--) {
                    if(skip + dp[j-1] < remaining) {
                        skip += dp[j-1];
                    } else {
                        ans += 'b';
                        remaining -= skip;
                        break;
                    }
                }
            } else {
                ans += 'a';
            }
        }
        
        std::reverse(ans.begin(), ans.end());
        std::cout << ans << std::endl;
    }
    
    return 0;
}