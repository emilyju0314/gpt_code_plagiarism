#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
};

double cross_product(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool segments_intersect(const Point& a, const Point& b, const Point& c, const Point& d) {
    return cross_product(a, b, c) * cross_product(a, b, d) < 0 && cross_product(c, d, a) * cross_product(c, d, b) < 0;
}

int main() {
    int n, w;
    std::cin >> n >> w;

    std::vector<Point> poly(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> poly[i].x >> poly[i].y;
    }

    int m;
    std::cin >> m;

    std::vector<Point> jellies(m);
    std::vector<int> r(m);

    for (int i = 0; i < m; ++i) {
        std::cin >> jellies[i].x >> jellies[i].y >> r[i];
    }

    int stingers = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (segments_intersect(poly[i], poly[(i + 1) % n], Point{0, -1000000000}, Point{0, 1000000000}) && std::abs(poly[i].x - poly[(i + 1) % n].x) <= r[j] && std::abs(poly[i].x - jellies[j].x) <= r[j]) {
                stingers++;
                break;
            }
        }
    }

    std::cout << stingers << std::endl;

    return 0;
}