#include <iostream>

bool isComposite(int n) {
    if(n <= 3)
        return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return true;
    }
    return false;
}

int main() {
    int q;
    std::cin >> q;

    for(int i = 0; i < q; i++) {
        int ni;
        std::cin >> ni;

        if(ni < 4) {
            std::cout << -1 << std::endl;
        } else if(ni % 2 == 0) {
            std::cout << ni / 4 << std::endl;
        } else {
            if(isComposite(ni - 9)) {
                std::cout << 1 + (ni - 9) / 4 << std::endl;
            } else {
                std::cout << -1 << std::endl;
            }
        }
    }

    return 0;
}