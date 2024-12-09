#include <iostream>
#include <vector>
#include <string>

#define MOD 998244353

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::string c;
    std::cin >> c;
    
    std::vector<int> left(n+10), right(n+10);
    left[0] = 1;
    right[n] = 1;
    
    for (int i = 1; i <= n; i++) {
        left[i] = (1LL * left[i-1] * 10) % MOD;
    }
    
    for (int i = n-1; i >= 0; i--) {
        right[i] = (1LL * right[i+1] * 10) % MOD;
    }
    
    int total = 0;
    for (int i = 0; i < n; i++) {
        total = (total + ((1LL * (c[i] - '0') * left[i]) % MOD)) % MOD;
    }
    
    while(m--) {
        int x, d;
        std::cin >> x >> d;
        x--;
        
        total = (total - ((1LL * (c[x] - '0') * left[x]) % MOD) + MOD) % MOD;
        total = (total + ((1LL * d * left[x]) % MOD)) % MOD;
        
        c[x] = d + '0';
        
        std::cout << (total * right[x+1]) % MOD << std::endl;
    }
    
    return 0;
}