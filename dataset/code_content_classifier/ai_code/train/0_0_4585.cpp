#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x;
    int y;
};

bool canFitAllPoints(int N, int H, int W, int R, std::vector<Point>& points) {
    for (int i = 0; i < N; i++) {
        if (points[i].x - R < 0) return false;
        if (points[i].x + R > W) return false;
        if (points[i].y - R < 0) return false;
        if (points[i].y + R > H) return false;
    }
    return true;
}

int main() {
    int N, H, W, R;
    std::cin >> N >> H >> W >> R;

    std::vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    if (canFitAllPoints(N, H, W, R, points)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}