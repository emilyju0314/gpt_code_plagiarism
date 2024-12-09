#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int m = 1;
    long long current_value = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << current_value << " ";
            current_value *= 10;
        }
        std::cout << std::endl;
    }

    return 0;
}