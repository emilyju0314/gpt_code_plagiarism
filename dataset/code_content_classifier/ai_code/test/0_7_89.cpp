#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        int a[n];
        bool possible = true;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            if (a[i] % (i + 1) != 0) {
                possible = false;
            }
        }

        if (possible) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}