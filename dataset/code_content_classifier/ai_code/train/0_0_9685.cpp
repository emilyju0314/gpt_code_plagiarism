#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;

    int totalTime = 0;
    for (int i = 0; i < M; i++) {
        totalTime += 1900 * (1 << M);
    }
    for (int i = 0; i < N - M; i++) {
        totalTime += 100 * (1 << M);
    }

    std::cout << totalTime << std::endl;

    return 0;
}