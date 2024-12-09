#include <iostream>

bool checkIfPossible(long long x, long long y) {
    if (x > y) {
        return false;
    }
    
    if (x == 1) {
        return (y == 1);
    }
    
    if (x == 2) {
        return (y == 2 || y == 4);
    }
    
    if (x == 3) {
        return (y == 3 || y == 6);
    }
    
    if (x == 4) {
        return (y == 4 || y == 8);
    }
    
    if (x == 5) {
        return (y == 5 || y == 10 || y == 20);
    }
    
    if (x % 2 == 1) {
        return ((x - 1) / 2 == y || (3 * x + 1) / 2 == y);
    } else {
        return (x / 2 == y);
    }
}

int main() {
    long long x, y;
    std::cin >> x >> y;
    
    if (checkIfPossible(x, y)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << stdjson::endl;
    }
    
    return 0;
}