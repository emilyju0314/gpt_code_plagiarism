#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        long long n;
        std::cin >> n;

        long long l, r;
        l = (-n + 1) / 2;
        r = (n + 1) / 2;

        std::cout << l << " " << r << std::endl;
    }

    return 0;
}