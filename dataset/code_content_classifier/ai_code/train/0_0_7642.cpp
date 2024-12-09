#include <iostream>

int minMoves(int n) {
    if(n == 1) {
        return 0;
    }
    if(n == 2) {
        return 1;
    }
    if(n % 2 == 0) {
        return 1 + minMoves(n / 2);
    }

    // Find the smallest proper divisor of n
    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) {
            return 1 + minMoves(i);
        }
    }
    return 1 + minMoves(n - 1);
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;
        std::cout << minMoves(n) << std::endl;
    }

    return 0;
}