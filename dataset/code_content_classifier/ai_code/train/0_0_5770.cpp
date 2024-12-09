#include <iostream>

int main() {
    int n, pos, l, r;
    std::cin >> n >> pos >> l >> r;

    int seconds = 0;
    if (l == 1 && r == n) {
        std::cout << 0 << std::endl;
        return 0;
    }

    if (l == 1) {
        seconds = abs(r - pos) + 1;
    } else if (r == n) {
        seconds = abs(l - pos) + 1;
    } else {
        seconds = std::min(abs(pos - l) + r - l, abs(pos - r) + r - l) + 2;
    }

    std::cout << seconds << std::endl;

    return 0;
}