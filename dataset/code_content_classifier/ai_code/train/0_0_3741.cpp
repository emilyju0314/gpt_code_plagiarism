#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        if(n % 2 == 0) {
            int ways = (n / 2) - 1;
            std::cout << ways << std::endl;
        } else {
            int ways = n / 2;
            std::cout << ways << std::endl;
        }
    }

    return 0;
}