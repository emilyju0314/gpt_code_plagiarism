#include <iostream>

int main() {
    int N, K, S;
    std::cin >> N >> K >> S;

    for (int i = 0; i < K; i++) {
        std::cout << S << " ";
    }

    for (int i = K; i < N; i++) {
        if (S == 1) {
            std::cout << 1000000000 << " ";
        } else {
            std::cout << 1 << " ";
        }
    }

    return 0;
}