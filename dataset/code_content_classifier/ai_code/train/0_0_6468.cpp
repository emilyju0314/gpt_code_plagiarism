#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        std::cout << i << " " << N-i+1 << "\n";
    }

    return 0;
}