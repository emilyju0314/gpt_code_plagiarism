#include <iostream>
#include <vector>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<std::vector<int>> table(n, std::vector<int>(n));
        std::vector<int> row_sum(n, 0);
        std::vector<int> col_sum(n, 0);

        // Input table values
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> table[i][j];
                row_sum[i] += table[i][j];
                col_sum[j] += table[i][j];
            }
        }

        // Output table with sums
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << std::right << std::setw(5) << table[i][j];
            }
            std::cout << std::setw(5) << row_sum[i] << std::endl;
        }

        for (int i = 0; i < n; ++i) {
            std::cout << std::right << std::setw(5) << col_sum[i];
        }
        std::cout << std::endl;
    }

    return 0;
} 

This code reads the input table values, calculates the sums of rows and columns, and then outputs the table with sums aligned to the right with the specified width of 5 characters. The program continues to read datasets until 0 is entered as input.