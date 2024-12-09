#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> sheet(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sheet[i];
    }

    int min_row = n, max_row = -1, min_col = m, max_col = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (sheet[i][j] == '*') {
                min_row = std::min(min_row, i);
                max_row = std::max(max_row, i);
                min_col = std::min(min_col, j);
                max_col = std::max(max_col, j);
            }
        }
    }

    for (int i = min_row; i <= max_row; i++) {
        for (int j = min_col; j <= max_col; j++) {
            std::cout << sheet[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}