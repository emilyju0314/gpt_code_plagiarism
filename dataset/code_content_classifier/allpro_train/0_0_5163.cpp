#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n % 2 != 0) {
        std::cout << "-1" << std::endl;
    } else {
        char grid[4][n];
        char colors[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        int colorIdx = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    grid[i][j] = colors[colorIdx];
                    grid[i + 1][j] = colors[colorIdx];
                    colorIdx = (colorIdx + 1) % 26;
                } else {
                    grid[i][j] = colors[colorIdx];
                    grid[i][j + 1] = colors[colorIdx];
                    colorIdx = (colorIdx + 1) % 26;
                }
                j++;
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << grid[i][j];
            }
            std::cout << std::endl;
        }
    }

    return 0;
}