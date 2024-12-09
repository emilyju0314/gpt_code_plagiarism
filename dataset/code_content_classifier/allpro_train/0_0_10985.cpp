#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> nails(N, std::vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        int Ai, Bi, Xi;
        std::cin >> Ai >> Bi >> Xi;
        nails[Ai-1][Bi-1]++;
        nails[Ai+Xi-1][Bi-1]++;
        nails[Ai+Xi-1][Bi+Xi-1]++;
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (nails[i][j] > 0) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}