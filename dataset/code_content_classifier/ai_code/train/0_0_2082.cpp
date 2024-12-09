#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> bag1(N);
    for (int i = 0; i < N; i++) {
        std::cin >> bag1[i];
    }

    std::vector<int> residues(M, 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (residues[j]) {
                residues[(j + bag1[i]) % M] = 1;
            }
        }
    }

    int K = 0;
    for (int i = 0; i < M; i++) {
        if (!residues[i]) {
            K++;
        }
    }

    std::cout << K << std::endl;

    if (K > 0) {
        std::vector<int> cannot_obtain;
        for (int i = 0; i < M; i++) {
            if (!residues[i]) {
                cannot_obtain.push_back(i);
            }
        }
        for (int i = 0; i < cannot_obtain.size(); i++) {
            std::cout << cannot_obtain[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}