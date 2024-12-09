#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> grid(n+1, std::vector<int>(m+1));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            char c;
            std::cin >> c;
            grid[i][j] = c - '0';
        }
    }

    int total_distance = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            int min_distance = n*n + m*m; // initialize with maximum possible value
            for(int x = 0; x <= n; x++) {
                for(int y = 0; y <= m; y++) {
                    if(grid[x][y] == 1) {
                        int distance = (i-x)*(i-x) + (j-y)*(j-y);
                        min_distance = std::min(min_distance, distance);
                    }
                }
            }
            total_distance += min_distance;
        }
    }

    std::cout << total_distance << std::endl;

    return 0;
}