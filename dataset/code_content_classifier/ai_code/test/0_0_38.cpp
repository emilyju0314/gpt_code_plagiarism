#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; i++) {
        std::cin >> grid[i];
    }

    std::vector<int> exitableCols(m + 1, 0);
    std::vector<int> exitableRows(n + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                exitableCols[j + 1]++;
                exitableRows[i + 1]++;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        exitableCols[i] += exitableCols[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        exitableRows[i] += exitableRows[i - 1];
    }

    int q;
    std::cin >> q;

    while (q--) {
        int x1, x2;
        std::cin >> x1 >> x2;

        int colsExitable = exitableCols[x2] - exitableCols[x1 - 1];
        int rowsExitable = exitableRows[n];

        for (int i = 0; i < n; i++) {
            if (x1 > 1 && grid[i][x1 - 2] == '.') {
                rowsExitable--;
            }
            if (grid[i][x2 - 1] == '.') {
                rowsExitable++;
            }
        }

        if (rowsExitable < colsExitable) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }

    return 0;
}