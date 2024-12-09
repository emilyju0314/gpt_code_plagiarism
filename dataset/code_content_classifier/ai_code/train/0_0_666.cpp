#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> hats(N);
    for (int i = 0; i < N; i++) {
        std::cin >> hats[i];
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        result ^= hats[i];
    }

    if (result == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}