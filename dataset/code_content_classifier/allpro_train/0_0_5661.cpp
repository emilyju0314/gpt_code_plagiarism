#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    if (n % 2 == 0) {
        std::cout << -1 << std::endl;
    } else {
        std::vector<int> a, b, c;
        for (int i = 0; i < n; i++) {
            a.push_back(i);
            b.push_back((i + 1) % n);
            c.push_back((2 * i) % n);
        }

        for (int i = 0; i < n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < n; i++) {
            std::cout << b[i] << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < n; i++) {
            std::cout << c[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}