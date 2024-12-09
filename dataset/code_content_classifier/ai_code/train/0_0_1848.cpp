#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int dp[100001] = {}, res = 0;
    
    for (int i = 0; i < n; i++) {
        dp[a[i]] = 1;
        for (int j = 2*a[i]; j < 100001; j += a[i]) {
            dp[a[i]] = std::max(dp[a[i]], dp[j]+1);
        }
        res = std::max(res, dp[a[i]]);
    }
    
    std::cout << res << std::endl;
    
    return 0;
}