#include <iostream>
#include <vector>

bool isValid(int x, int y) {
    return x >= 0 && x < 9 && y >= 0 && y < 9;
}

int main() {
    std::vector<std::vector<char>> grid(9, std::vector<char>(9));

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cin >> grid[i][j];
            if (grid[i][j] == '.') {
                grid[i][j] = '!';
            }
        }
    }

    int x, y;
    std::cin >> x >> y;

    x--;
    y--;

    char currPlayer = (grid[x][y] == 'x') ? 'o' : 'x';

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (grid[i][j] == '.' && (i / 3 == x / 3 && j / 3 == y / 3)) {
                grid[i][j] = '!';
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << grid[i][j];
            if (j == 2 || j == 5) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
        if (i == 2 || i == 5) {
            std::cout << "\n";
        }
    }

    return 0;
}