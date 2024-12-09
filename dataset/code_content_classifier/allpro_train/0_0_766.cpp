#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct Point {
    double x, y;
};

struct Block {
    double minx, miny, maxx, maxy, height;
};

bool isColliding(Point start, Point end, Block b) {
    double x1 = b.minx, x2 = b.maxx, y1 = b.miny, y2 = b.maxy;
    double m = (end.y - start.y) / (end.x - start.x);
    double c = start.y - m * start.x;
    double y = m * x1 + c;
    if ((y >= y1 && y <= y2) || (y <= y1 && y >= y2)) {
        return true;
    }
    y = m * x2 + c;
    if ((y >= y1 && y <= y2) || (y <= y1 && y >= y2)) {
        return true;
    }
    return false;
}

double largestRadius(Point start, Point end, std::vector<Block>& blocks) {
    double largestR = 1000;
    for (const Block& block : blocks) {
        if (isColliding(start, end, block)) {
            largestR = 0;
            break;
        }
        for (double x : {block.minx, block.maxx}) {
            for (double y : {block.miny, block.maxy}) {
                double d = std::sqrt((start.x - x) * (start.x - x) + (start.y - y) * (start.y - y));
                largestR = std::min(largestR, d);
            }
        }
    }
    return largestR;
}

int main() {
    int N, n = 1;
    while (std::cin >> N && N) {
        double sx, sy, ex, ey;
        std::cin >> sx >> sy >> ex >> ey;

        std::vector<Block> blocks(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> blocks[i].minx >> blocks[i].miny >> blocks[i].maxx >> blocks[i].maxy >> blocks[i].height;
        }

        double result = largestRadius({sx, sy}, {ex, ey}, blocks);
        std::cout << std::fixed << std::setprecision(12) << result << "\n";
    }

    return 0;
}