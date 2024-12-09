#include <iostream>
#include <vector>

int main() {
    int N;
    while (std::cin >> N) {
        if (N == 0) {
            break;
        }

        std::vector<int> row_sums(N);
        std::vector<int> col_sums(N);

        // Read row sums
        for (int i = 0; i < N; i++) {
            std::cin >> row_sums[i];
        }

        // Read column sums
        for (int i = 0; i < N; i++) {
            std::cin >> col_sums[i];
        }

        bool possible = true;

        for (int i = 0; i < N; i++) {
            int row_sum = 0;
            int col_sum = 0;
            for (int j = 0; j < N; j++) {
                row_sum += (row_sums[j] == i + 1);
                col_sum += (col_sums[j] == i + 1);
            }
            if (row_sum != col_sums[i] || col_sum != row_sums[i]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}