#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        // Find three distinct positive integers a, b, c satisfying a + b + c = n
        // and gcd(a, b) = c. One possible solution is:
        // a = n/2 - 1, b = n/2 + 1, c = 1
        std::cout << n/2 - 1 << " " << n/2 + 1 << " " << 1 << std::endl;
    }

    return 0;
}