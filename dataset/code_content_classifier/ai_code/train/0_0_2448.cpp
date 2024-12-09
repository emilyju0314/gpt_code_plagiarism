#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        long long n;
        std::cin >> n;

        if(n % 2 == 0) {
            std::cout << n / 2 << std::endl;
        } else {
            std::cout << (n - 1) / 2 << std::endl;
        }
    }

    return 0;
}