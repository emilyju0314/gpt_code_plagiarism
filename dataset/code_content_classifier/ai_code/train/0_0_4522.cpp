#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int l, r;
        std::cin >> l >> r;

        // If the range (r - l + 1) is greater than or equal to a/2, then choosing a = 2*(r - l + 1) will make each customer buy more cans than they wanted initially
        if (r - l + 1 >= (r - l + 1) / 2) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}