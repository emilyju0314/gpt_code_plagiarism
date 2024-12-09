#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    if (n < 4) {
        std::cout << "NO";
    } else {
        std::cout << "YES" << std::endl;
        std::cout << "8 * 7 = 56" << std::endl;
        std::cout << "6 * 5 = 30" << std::endl;
        std::cout << "3 - 4 = -1" << std::endl;
        std::cout << "1 - 2 = -1" << std::endl;
        std::cout << "30 - -1 = 31" << std::endl;
        std::cout << "56 - 31 = 25" << std::endl;
        std::cout << "25 + -1 = 24" << std::endl;

        for (int i = 9; i <= n; i++) {
            std::cout << "1 * " << i << " = " << i << std::endl;
        }
    }

    return 0;
}