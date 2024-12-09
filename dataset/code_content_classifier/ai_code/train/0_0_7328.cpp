#include <iostream>
#include <vector>

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<bool>> grid(n, std::vector<bool>(m, false));

    for (int i = 0; i < q; i++) {
        int t, r1, c1, r2, c2;
        std::cin >> t >> r1 >> c1 >> r2 >> c2;

        if (t == 1) {
            for (int r = r1; r <= r2; r++) {
                for (int c = c1; c <= c2; c++) {
                    grid[r-1][c-1] = true;
                }
            }
        } else if (t == 2) {
            bool feasible = true;
            for (int r = r1; r <= r2; r++) {
                for (int c = c1; c <= c2; c++) {
                    if (!grid[r-1][c-1]) {
                        feasible = false;
                        break;
                    }
                }
                if (!feasible) break;
            }
            if (feasible) {
                for (int r = r1; r <= r2; r++) {
                    for (int c = c1; c <= c2; c++) {
                        grid[r-1][c-1] = false;
                    }
                }
            }
        } else if (t == 3) {
            bool feasible = true;
            for (int r = r1; r <= r2; r++) {
                for (int c = c1; c <= c2; c++) {
                    if (grid[r-1][c-1]) {
                        feasible = false;
                        break;
                    }
                }
                if (!feasible) break;
            }
            if (feasible) {
                std::cout << "Yes" << "\n";
            } else {
                std::cout << "No" << "\n";
            }
        }
    }

    return 0;
}