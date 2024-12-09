#include <iostream>
#include <vector>

struct Grid {
    bool cells[5][5][5];
};

void applyRules(Grid& grid, int M1, int ai[], int M2, int bj[]) {
    // Implement the rules of birth and death for the given grid and values of M1, ai, M2, and bj
    // You can update the cells in the grid accordingly
}

void printGrid(const Grid& grid) {
    for (int z = 0; z < 5; z++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                std::cout << grid.cells[z][y][x];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    int N, M1, M2;
    while (std::cin >> N && N != 0) {
        Grid grid;
        for (int z = 0; z < 5; z++) {
            for (int y = 0; y < 5; y++) {
                std::string row;
                std::cin >> row;
                for (int x = 0; x < 5; x++) {
                    grid.cells[z][y][x] = row[x] == '1';
                }
            }
        }

        int ai[27], bj[27];
        std::cin >> M1;
        for (int i = 0; i < M1; i++) {
            std::cin >> ai[i];
        }

        std::cin >> M2;
        for (int i = 0; i < M2; i++) {
            std::cin >> bj[i];
        }

        for (int day = 0; day < N; day++) {
            applyRules(grid, M1, ai, M2, bj);
        }

        std::cout << "Case: ";
        printGrid(grid);
    }

    return 0;
}