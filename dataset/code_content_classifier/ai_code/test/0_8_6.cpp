#include <iostream>
#include <algorithm>
#include <numeric>

const int MOD = 1e9 + 7;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    int n;
    std::cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    long long result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = (result + 1LL * gcd(a[i], a[j]) * gcd(i+1, j+1)) % MOD;
        }
    }
    
    std::cout << result << std::endl;
    
    return 0;
}