#include <iostream>

bool isComposite(int n) {
    if (n < 4) {
        return false;
    }
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 4; i <= n/2; i++) {
        if (isComposite(i) && isComposite(n-i)) {
            std::cout << i << " " << n-i << std::endl;
            break;
        }
    }

    return 0;
}