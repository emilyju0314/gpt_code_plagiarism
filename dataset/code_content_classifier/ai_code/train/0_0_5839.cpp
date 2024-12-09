#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> table(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> table[i];
    }

    int columnsToRemove = 0;
    for (int j = 0; j < m; ++j) {
        bool isGood = true;
        for (int i = 0; i < n - 1; ++i) {
            if (table[i][j] > table[i + 1][j]) {
                isGood = false;
                break;
            }
        }
        if (!isGood) {
            ++columnsToRemove;
        }
    }

    std::cout << columnsToRemove << std::endl;

    return 0;
}