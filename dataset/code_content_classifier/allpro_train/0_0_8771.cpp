#include <iostream>
#include <cmath>

bool isTriangularNumber(int n) {
    int x = sqrt(2*n);
    return x*(x+1)/2 == n;
}

int main() {
    int n;
    std::cin >> n;

    bool found = false;
    for(int i = 1; i <= n; i++) {
        if(isTriangularNumber(i) && isTriangularNumber(n-i)) {
            found = true;
            break;
        }
    }

    if(found) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}