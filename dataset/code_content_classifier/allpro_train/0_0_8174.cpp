#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> table(n, std::vector<int>(m));

    int good_cells = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> table[i][j];
            if (table[i][j] == 1) good_cells++;
        }
    }

    int operations = 0;

    // Color all rows
    operations += n;

    // Color all columns
    operations += m;

    // For each good cell, color the entire row and column it belongs to
    // Counting duplicates as they are colored multiple times
    operations += good_cells * 2;

    // Subtracting the overlapping corner cells
    operations -= 4;

    std::cout << operations << std::endl;

    return 0;
}