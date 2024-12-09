#include <iostream>
#include <vector>
#include <algorithm>

struct Rectangle {
    int top, bottom, left, right;
};

void countRegions(std::vector<Rectangle> rectangles) {
    int n = rectangles.size();
    std::vector<int> x_coords;
    std::vector<int> y_coords;

    for (int i = 0; i < n; i++) {
        x_coords.push_back(rectangles[i].left);
        x_coords.push_back(rectangles[i].right);
        y_coords.push_back(rectangles[i].top);
        y_coords.push_back(rectangles[i].bottom);
    }

    // Sort and unique the x and y coordinates
    std::sort(x_coords.begin(), x_coords.end());
    std::sort(y_coords.begin(), y_coords.end());
    x_coords.erase(std::unique(x_coords.begin(), x_coords.end()), x_coords.end());
    y_coords.erase(std::unique(y_coords.begin(), y_coords.end()), y_coords.end());

    // Create a grid to track regions
    std::vector<std::vector<int>> grid(x_coords.size(), std::vector<int>(y_coords.size(), 0));

    // Mark regions enclosed by rectangles
    for (Rectangle rect : rectangles) {
        int x1 = std::lower_bound(x_coords.begin(), x_coords.end(), rect.left) - x_coords.begin();
        int x2 = std::lower_bound(x_coords.begin(), x_coords.end(), rect.right) - x_coords.begin();
        int y1 = std::lower_bound(y_coords.begin(), y_coords.end(), rect.bottom) - y_coords.begin();
        int y2 = std::lower_bound(y_coords.begin(), y_coords.end(), rect.top) - y_coords.begin();

        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                grid[i][j] = 1;
            }
        }
    }

    // Count the number of regions
    int regions = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 0) {
                regions++;
                grid[i][j] = 1;
                // DFS to mark connected regions
                std::vector<std::pair<int, int>> stack = {{i, j}};
                while (!stack.empty()) {
                    int x = stack.back().first;
                    int y = stack.back().second;
                    stack.pop_back();
                    if (x > 0 && grid[x-1][y] == 0) {
                        grid[x-1][y] = 1;
                        stack.push_back({x-1, y});
                    }
                    if (x < grid.size()-1 && grid[x+1][y] == 0) {
                        grid[x+1][y] = 1;
                        stack.push_back({x+1, y});
                    }
                    if (y > 0 && grid[x][y-1] == 0) {
                        grid[x][y-1] = 1;
                        stack.push_back({x, y-1});
                    }
                    if (y < grid[0].size()-1 && grid[x][y+1] == 0) {
                        grid[x][y+1] = 1;
                        stack.push_back({x, y+1});
                    }
                }
            }
        }
    }

    std::cout << regions << std::endl;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Rectangle> rectangles(n);
        for (int i = 0; i < n; i++) {
            std::cin >> rectangles[i].left >> rectangles[i].top >> rectangles[i].right >> rectangles[i].bottom;
        }

        countRegions(rectangles);
    }

    return 0;
}