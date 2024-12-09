#include <iostream>
#include <algorithm>

int main() {
    int l, r, a;
    std::cin >> l >> r >> a;

    int teamSize = 2 * std::min(l, r) + 2 * (std::min(std::max(l, r), a / 2));
    std::cout << teamSize << std::endl;

    return 0;
}