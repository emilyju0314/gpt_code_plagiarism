#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;

        if(x % 3 == 0 || x % 7 == 0 || x % 3 + x % 7 <= 7) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}