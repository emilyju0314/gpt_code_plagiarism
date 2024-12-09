#include <iostream>
#include <vector>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> instructions(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> instructions[i][j];
        }
    }

    std::vector<int> locked_cycles(n, 0);
    std::vector<std::vector<bool>> locked_cell(k + 1, std::vector<bool>(n + 1, false));

    for (int cycle = 1; cycle <= m; ++cycle) {
        for (int core = 0; core < n; ++core) {
            if (locked_cycles[core] == 0) {
                int cell = instructions[core][cycle - 1];
                if (cell != 0 && locked_cell[cell][0]) {
                    locked_cycles[core] = cycle;
                } else if (cell != 0) {
                    locked_cell[cell][0] = true;
                    locked_cell[cell][core + 1] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << locked_cycles[i] << std::endl;
    }

    return 0;
}