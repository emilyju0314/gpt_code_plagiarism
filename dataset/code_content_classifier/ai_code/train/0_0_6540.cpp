#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> left_gcd(n);
    std::vector<int> right_gcd(n);
    
    left_gcd[0] = a[0];
    right_gcd[n-1] = a[n-1];
    
    for(int i = 1; i < n; i++) {
        left_gcd[i] = gcd(left_gcd[i-1], a[i]);
    }
    
    for(int i = n-2; i >= 0; i--) {
        right_gcd[i] = gcd(right_gcd[i+1], a[i]);
    }
    
    long long ans = 0;
    
    for(int i = 0; i < n-1; i++) {
        int max_gcd = gcd(left_gcd[i], right_gcd[i+1]);
        ans = std::max(ans, (long long)max_gcd * (i+1) * (n-i-1));
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}