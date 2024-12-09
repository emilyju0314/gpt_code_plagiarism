#include <iostream>

int main() {
    int N, K;
    std::cin >> N >> K;

    if (K <= N / 2 && N >= K * 2 - 1) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}