#include <iostream>

int main() {
    int e;

    while (std::cin >> e && e != 0) {
        int m = e; // Initialize m to e

        for (int x = 0; x <= e; x++) {
            for (int y = 0; y * y <= e; y++) {
                int z = e - x - y * y;
                if (z < 0) continue;

                if (x + y + z < m) {
                    m = x + y + z;
                }
            }
        }

        std::cout << m << std::endl;
    }

    return 0;
}