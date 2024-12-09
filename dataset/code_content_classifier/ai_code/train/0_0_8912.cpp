#include <iostream>

int W, H, S;
int counter = 0;

bool isValid(int grid[8][8], int x, int y) {
    return x >= 0 && x < W && y >= 0 && y < H && grid[y][x] == 0;
}

void placeObstacle(int grid[8][8], int x, int y, int remainingObstacles) {
    if (x == W - 1 && y == H - 1) {
        if (remainingObstacles == 0) {
            counter++;
        }
        return;
    }

    int nextX = (x + 1) % W;
    int nextY = y + (nextX == 0);
    
    if (isValid(grid, x, y)) {
        grid[y][x] = 1;
        placeObstacle(grid, nextX, nextY, remainingObstacles - 1);
        grid[y][x] = 0;
    }
    
    placeObstacle(grid, nextX, nextY, remainingObstacles);
}

int main() {
    int grid[8][8] = {0};
    std::cin >> W >> H >> S;
    
    placeObstacle(grid, 0, 0, S);
    
    std::cout << counter << std::endl;

    return 0;
}