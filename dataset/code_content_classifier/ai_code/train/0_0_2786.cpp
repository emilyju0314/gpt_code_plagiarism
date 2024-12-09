#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        // Output a complete array
        for(int i = 1; i <= n; i++) {
            // The pattern could be any non-repeating values
            std::cout << i * 3 << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}