#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);
    std::vector<std::vector<int>> prefix_sum(n, std::vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++) {
        std::cin >> grid[i];
        for (int j = 1; j <= m; j++) {
            prefix_sum[i][j] = prefix_sum[i][j - 1] + (grid[i][j-1] == '.');
        }
    }

    int q;
    std::cin >> q;

    while (q--) {
        int x1, x2;
        std::cin >> x1 >> x2;

        bool determinable = true;
        for (int i = 0; i < n; i++) {
            if (prefix_sum[i][x2] - prefix_sum[i][x1 - 1] == 0) {
                determinable = false;
                break;
            }
        }

        if (determinable) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}