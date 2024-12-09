#include <iostream>
#include <string>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;

    std::string a;
    std::cin >> a;

    int transitions = 0;
    bool has_zero = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == '0') {
            if (i > 0 && a[i-1] == '1') {
                transitions++;
            }
            has_zero = true;
        }
    }

    if (!has_zero) {
        std::cout << 0 << std::endl;
    } else if (y < x) {
        std::cout << (transitions + 1) * y << std::endl;
    } else {
        std::cout << transitions * x + y << std::endl;
    }

    return 0;
}