#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n, k;
        std::cin >> n >> k;

        int diff = abs(n - k);
        if(n >= k) {
            if(diff % 2 == 0) {
                std::cout << 0 << std::endl;
            } else {
                std::cout << 1 << std::endl;
            }
        } else {
            std::cout << k - n << std::endl;
        }
    }

    return 0;
}