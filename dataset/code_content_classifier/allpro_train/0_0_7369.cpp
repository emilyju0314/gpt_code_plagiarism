#include <iostream>

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int n, k;
        std::cin >> n >> k;

        if (n % (k + 1) == 0) {
            std::cout << "Bob" << std::endl;
        } else {
            std::cout << "Alice" << std::endl;
        }
    }

    return 0;
}