#include <iostream>

int main() {
    int K, X;
    std::cin >> K >> X;

    for(int i = X - K + 1; i <= X + K - 1; i++) {
        std::cout << i << " ";
    }

    return 0;
}