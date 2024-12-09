#include <iostream>
#include <vector>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> table(n, std::vector<int>(m, 0));

    for (int i = 0; i < k; i++) {
        int op, r, a;
        std::cin >> op >> r >> a;

        if (op == 1) {
            for (int j = 0; j < m; j++) {
                table[r-1][j] = a;
            }
        } else {
            for (int j = 0; j < n; j++) {
                table[j][r-1] = a;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}