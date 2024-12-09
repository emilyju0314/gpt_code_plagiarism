#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y, z;
};

bool ccw(Point a, Point b, Point c) {
    return (c.z - a.z) * (b.y - a.y) > (b.z - a.z) * (c.y - a.y);
}

bool intersect(Point a, Point b, Point c, Point d) {
    return (ccw(a, c, d) != ccw(b, c, d)) && (ccw(a, b, c) != ccw(a, b, d));
}

int main() {
    int n, m;
    std::cin >> n;
    std::vector<Point> polygon1(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> polygon1[i].x >> polygon1[i].y >> polygon1[i].z;
    }

    std::cin >> m;
    std::vector<Point> polygon2(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> polygon2[i].x >> polygon2[i].y >> polygon2[i].z;
    }

    bool isWellConnected = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (intersect(polygon1[i], polygon1[(i+1)%n], polygon2[j], polygon2[(j+1)%m])) {
                isWellConnected = true;
                break;
            }
        }
        if (isWellConnected) {
            break;
        }
    }

    if (isWellConnected) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}