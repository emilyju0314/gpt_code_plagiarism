#include <iostream>
#include <vector>

int findLargestRectangle(std::vector<std::vector<int>>& grid) {
    int maxRectangleSize = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                int width = 1;
                int height = 1;

                while ((j + width) < grid[0].size() && grid[i][j + width] == 1) {
                    int currentHeight = 1;

                    while ((i + currentHeight) < grid.size() && grid[i + currentHeight][j + width] == 1) {
                        currentHeight++;
                    }

                    height = std::min(height, currentHeight);
                    width++;
                }

                maxRectangleSize = std::max(maxRectangleSize, width * height);
            }
        }
    }

    return maxRectangleSize;
}

int main() {
    int m;
    std::cin >> m;

    for (int k = 0; k < m; k++) {
        std::vector<std::vector<int>> grid(5, std::vector<int>(5));

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                char c;
                std::cin >> c;
                grid[i][j] = (c == '1');
            }
        }

        int largestRectangleSize = findLargestRectangle(grid);
        std::cout << largestRectangleSize << std::endl;
    }

    return 0;
}