#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::vector<int>>> pieces(4, std::vector<std::vector<int>>(n, std::vector<int>(n)));

    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char color;
                std::cin >> color;
                pieces[k][i][j] = color - '0';
            }
        }
    }

    int min_changes = INT_MAX;
    for (int k = 0; k < 4; k++) {
        int changes = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Calculate the changes needed for each cell
                if ((i + j) % 2 == 0 && pieces[k][i][j] != 0) {
                    changes++;
                } else if ((i + j) % 2 == 1 && pieces[k][i][j] != 1) {
                    changes++;
                }
            }
        }
        min_changes = std::min(min_changes, changes);
    }

    std::cout << min_changes << std::endl;

    return 0;
}