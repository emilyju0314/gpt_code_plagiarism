#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> scores(N, std::vector<int>(3));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> scores[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        int total = 0;
        for (int j = 0; j < 3; j++) {
            int count = 0;
            for (int k = 0; k < 3; k++) {
                if (j != k && scores[i][j] == scores[i][k]) {
                    count++;
                }
            }
            if (count == 0) {
                total += scores[i][j];
            }
        }
        std::cout << total << std::endl;
    }

    return 0;
}