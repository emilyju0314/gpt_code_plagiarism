#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> c(m);
    for(int i = 0; i < m; i++) {
        std::cin >> c[i];
    }
    
    std::vector<int> dp(m + 1);
    dp[0] = 1;
    
    int total = 0;
    
    for(int i = 1; i <= n; i++) {
        int last = 0;
        std::vector<int> pre(m + 1);
        
        for(int j = 0; j <= m; j++) {
            if (c[j] == i) {
                pre[j] = last;
                last = j;
            }
        }
        
        for(int j = 0; j < m; j++) {
            int val = 0;
            for(int k = pre[j]; k <= j; k++) {
                val = (val + dp[k]) % MOD;
            }
            dp[j + 1] = val;
        }
        
        total = (total + dp[m]) % MOD;
    }
    
    std::cout << total << std::endl;
    
    return 0;
}