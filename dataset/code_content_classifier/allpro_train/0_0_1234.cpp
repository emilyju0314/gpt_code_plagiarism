#include <iostream>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int total = a + b + c + d;

    if (abs(a - b) > 1 || abs(c - d) > 1) {
        std::cout << "NO" << std::endl;
    } else if (a > b && c > d) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
        for (int i = 0; i < total; i++) {
            if (i % 2 == 0) {
                if (a > 0) {
                    std::cout << "0 ";
                    a--;
                } else {
                    std::cout << "1 ";
                    b--;
                }
            } else {
                if (c > 0) {
                    std::cout << "2 ";
                    c--;
                } else {
                    std::cout << "3 ";
                    d--;
                }
            }
        }
        std::cout << std::endl;
    }

    return 0;
}