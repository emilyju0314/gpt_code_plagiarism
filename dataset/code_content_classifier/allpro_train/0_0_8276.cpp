#include <iostream>

int main() {
    int t, s, x;
    std::cin >> t >> s >> x;

    if (t == x) {
        std::cout << "YES\n";
    } else if ((x > t + s) && ((x - t) % s == 0 || (x - t - 1) % s == 0)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}