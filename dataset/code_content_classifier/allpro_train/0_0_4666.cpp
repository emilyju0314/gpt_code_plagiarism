#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
    bool isBlack;
};

bool canSeparatePoints(const std::vector<Point>& points) {
    for (const auto& p : points) {
        for (const auto& q : points) {
            if (p.isBlack != q.isBlack) {
                int a = q.y - p.y;
                int b = p.x - q.x;
                int c = -a * p.x - b * p.y;
                bool valid = true;
                for (const auto& r : points) {
                    if ((a * r.x + b * r.y + c) * (p.isBlack ? -1 : 1) <= 0) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    while (std::cin >> n >> m && n != 0 && m != 0) {
        std::vector<Point> points;
        for (int i = 0; i < n + m; ++i) {
            int x, y;
            std::cin >> x >> y;
            points.push_back({x, y, i < n});
        }
        std::cout << (canSeparatePoints(points) ? "YES" : "NO") << std::endl;
    }
    return 0;
}