#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;

    long long ans = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            ans = __gcd(ans, i);
        }
    }
    
    if (n > 1) {
        ans = __gcd(ans, n);
    }

    std::cout << ans << std::endl;

    return 0;
}