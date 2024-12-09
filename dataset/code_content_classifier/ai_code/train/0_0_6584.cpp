#include <iostream>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    if(n == 1 && m == 1) {
        std::cout << 0 << std::endl;
    } else if(n == 1 || m == 1) {
        std::cout << std::max(n, m) - 2 << std::endl;
    } else {
        std::cout << n * m - 2 << std::endl;
    }

    return 0;
}