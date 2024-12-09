#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::string>> initial(n, std::vector<std::string>(m));
    std::vector<std::vector<std::string>> final(n, std::vector<std::string>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> initial[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> final[i][j];
        }
    }

    std::vector<std::vector<std::vector<int>>> operations;

    int totalLength = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            totalLength += initial[i][j].size();
        }
    }

    std::cout << 4 * totalLength << std::endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int targetRow = -1, targetCol = -1;
            for (int k = 0; k < n; k++) {
                if (initial[k][j] == final[i][j] && k != i) {
                    targetRow = k;
                    targetCol = j;
                    break;
                }
            }

            if (targetRow == -1) {
                for (int k = 0; k < m; k++) {
                    if (initial[i][k] == final[i][j] && k != j) {
                        targetRow = i;
                        targetCol = k;
                        break;
                    }
                }
            }

            while (initial[i][j] != final[i][j]) {
                if (targetRow != i) {
                    std::cout << i + 1 << " " << j + 1 << " " << targetRow + 1 << " " << j + 1 << std::endl;
                    initial[targetRow][j] = initial[i][j].back() + initial[targetRow][j];
                    initial[i][j].pop_back();
                } else {
                    std::cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << targetCol + 1 << std::endl;
                    initial[i][targetCol] = initial[i][j].back() + initial[i][targetCol];
                    initial[i][j].pop_back();
                }
            }
        }
    }

    return 0;
}