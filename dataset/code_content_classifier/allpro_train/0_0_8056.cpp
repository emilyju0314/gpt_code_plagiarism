#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> bag1(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> bag1[i];
    }

    std::vector<bool> possible(M, false);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            possible[(bag1[i] + bag1[j]) % M] = true;
        }
    }

    int K = 0;
    for (bool p : possible) {
        if (!p) {
            ++K;
        }
    }

    std::cout << K << "\n";
    if (K > 0) {
        for (int i = 0; i < M; ++i) {
            if (!possible[i]) {
                std::cout << i << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}