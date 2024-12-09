#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        for (int i = 1; i <= n; i++) {
            std::cout << i << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}