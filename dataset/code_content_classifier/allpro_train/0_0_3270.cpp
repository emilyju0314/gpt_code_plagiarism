#include <iostream>

int main() {
    int N, K;
    std::cin >> N >> K;

    int value = 1;
    for (int i = 0; i < N; i++) {
        if (value * 2 < value + K) {
            value *= 2;
        } else {
            value += K;
        }
    }

    std::cout << value << std::endl;

    return 0;
}