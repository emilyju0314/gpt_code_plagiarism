#include <iostream>

int main() {
    int n;
    
    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }
        
        long long dp[31] = {0};
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        
        long long total_climbs = dp[n] / 10;
        long long years = total_climbs / 365;
        if (total_climbs % 365 != 0) {
            years++;
        }
        
        std::cout << years << std::endl;
    }
    
    return 0;
}