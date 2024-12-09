#include <iostream>

const int MOD = 1000000007;

int main() {
    long long n, m, k;
    std::cin >> n >> m >> k;

    if(k == -1 && (n % 2 != m % 2)) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 1 << std::endl;
    }

    return 0;
}