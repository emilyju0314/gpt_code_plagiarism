#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> table(n, std::vector<int>(m));
    std::vector<int> row_operations(n, 0);
    std::vector<int> col_operations(m, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> table[i][j];
            if(table[i][j] < 0) {
                row_operations[i]++;
                col_operations[j]++;
            }
        }
    }

    int count_row = 0, count_col = 0;
    std::vector<int> row_indexes, col_indexes;

    for(int i = 0; i < n; i++) {
        if(row_operations[i] % 2 != 0) {
            count_row++;
            row_indexes.push_back(i + 1);
        }
    }

    for(int j = 0; j < m; j++) {
        if(col_operations[j] % 2 != 0) {
            count_col++;
            col_indexes.push_back(j + 1);
        }
    }

    std::cout << count_row << " ";
    for(int i = 0; i < row_indexes.size(); i++) {
        std::cout << row_indexes[i] << " ";
    }
    std::cout << std::endl;

    std::cout << count_col << " ";
    for(int j = 0; j < col_indexes.size(); j++) {
        std::cout << col_indexes[j] << " ";
    }
    std::cout << std::endl;

    return 0;
}