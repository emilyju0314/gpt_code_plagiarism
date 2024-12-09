#include <iostream>
#include <algorithm>

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long long a, b;
        std::cin >> a >> b;

        if (a == b) {
            std::cout << "0 0" << std::endl;
        } else {
            long long diff = std::abs(a - b);
            long long excite = gcd(a, b);
            std::cout << excite << " " << diff << std::endl;
        }
    }

    return 0;
}