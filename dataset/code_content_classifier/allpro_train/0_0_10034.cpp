#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;

    while (std::cin >> N && N != 0) {
        std::vector<int> myMonsters(N);
        std::vector<int> opponentMonsters(N);

        for (int i = 0; i < N; i++) {
            std::cin >> myMonsters[i];
        }

        for (int i = 0; i < N; i++) {
            std::cin >> opponentMonsters[i];
        }

        std::sort(myMonsters.begin(), myMonsters.end());
        std::sort(opponentMonsters.begin(), opponentMonsters.end());

        int minK = 0;
        for (int i = 0; i < N; i++) {
            if (myMonsters[i] >= opponentMonsters[N - i - 1]) {
                minK = std::max(minK, i + 1);
            }
        }

        if (minK < N) {
            std::cout << minK << std::endl;
        } else {
            std::cout << "NA" << std::endl;
        }
    }

    return 0;
}