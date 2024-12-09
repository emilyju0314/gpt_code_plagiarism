#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n, m;
        std::cin >> n >> m;

        if(n == 1) {
            std::cout << "0" << std::endl;
        } else if(n <= m) {
            std::cout << "1" << std::endl;
        } else {
            std::cout << n - m << std::endl;
        }
    }

    return 0;
}