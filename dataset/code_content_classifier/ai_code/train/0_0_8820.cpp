#include <iostream>
#include <vector>

int main() {
    int N, Q;
    while (std::cin >> N >> Q) {
        if (N == 0 && Q == 0) {
            break;
        }

        std::vector<std::vector<int>> dates(100, std::vector<int>(50, 0));

        for (int i = 0; i < N; i++) {
            int M;
            std::cin >> M;
            for (int j = 0; j < M; j++) {
                int date;
                std::cin >> date;
                dates[date][i]++;
            }
        }

        int maxCount = 0;
        int bestDate = 0;

        for (int i = 1; i < 100; i++) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (dates[i][j] > 0) {
                    count++;
                }
            }
            if (count >= Q && count > maxCount) {
                maxCount = count;
                bestDate = i;
            }
        }

        std::cout << (bestDate == 0 ? 0 : bestDate) << std::endl;
    }

    return 0;
}