#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                std::cout << "24";
            } else {
                std::cout << " 77";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}