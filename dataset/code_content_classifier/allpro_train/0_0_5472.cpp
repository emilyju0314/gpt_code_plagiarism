#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        long long n, k;
        std::cin >> n >> k;

        long long ans = n;
        for(long long i = 1; i <= k; i++) {
            if(n % i == 0) {
                long long p = n / i;
                ans = std::min(ans, p * k + i);
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}