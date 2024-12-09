#include <iostream>
#include <vector>

int main() {
    int W, H, N;
    std::cin >> W >> H >> N;

    // Create a 2D vector to represent the grid of tiles
    std::vector<std::vector<int>> grid(H, std::vector<int>(W, 0));

    for (int i = 0; i < N; i++) {
        int ax, ay, bx, by;
        std::cin >> ax >> ay >> bx >> by;

        // Fill the rectangle with black tiles
        for (int y = ay - 1; y <= by - 1; y++) {
            for (int x = ax - 1; x <= bx - 1; x++) {
                grid[y][x] = 1;
            }
        }

        // Count the number of black tiles
        int blackTiles = 0;
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                blackTiles += grid[y][x];
            }
        }

        std::cout << blackTiles << std::endl;
    }

    return 0;
}