#include <iostream>
#include <vector>
#include <string>

int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> grid(H);
    for (int i = 0; i < H; i++) {
        std::cin >> grid[i];
    }

    std::vector<bool> removeRow(H, false);
    std::vector<bool> removeCol(W, false);

    for (int i = 0; i < H; i++) {
        bool allWhite = true;
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') {
                allWhite = false;
                break;
            }
        }
        if (allWhite) {
            removeRow[i] = true;
        }
    }

    for (int j = 0; j < W; j++) {
        bool allWhite = true;
        for (int i = 0; i < H; i++) {
            if (grid[i][j] == '#') {
                allWhite = false;
                break;
            }
        }
        if (allWhite) {
            removeCol[j] = true;
        }
    }

    for (int i = 0; i < H; i++) {
        if (removeRow[i]) continue;
        for (int j = 0; j < W; j++) {
            if (!removeCol[j]) {
                std::cout << grid[i][j];
            }
        }
        std::cout << std::endl;
    }

    return 0;
}