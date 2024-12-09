#include <iostream>

int main() {
    int r, c;
    std::cin >> r >> c;

    int table[101][101] = {0};
    int row_sums[101] = {0};
    int col_sums[101] = {0};
    int total_sum = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cin >> table[i][j];
            row_sums[i] += table[i][j];
            col_sums[j] += table[i][j];
            total_sum += table[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cout << table[i][j] << " ";
        }
        std::cout << row_sums[i] << std::endl;
    }

    for (int j = 0; j < c; j++) {
        std::cout << col_sums[j] << " ";
    }
    std::cout << total_sum << std::endl;

    return 0;
}