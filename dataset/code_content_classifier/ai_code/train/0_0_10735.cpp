#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x, y;
};

int crossProduct(Point p1, Point p2, Point p0) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

int polygonArea(std::vector<Point>& polygon) {
    int area = 0;
    for (int i = 0; i < polygon.size(); i++) {
        int j = (i + 1) % polygon.size();
        area += polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y;
    }
    return std::abs(area) / 2;
}

bool isInsidePolygon(Point pt, std::vector<Point>& polygon) {
    int windingNumber = 0;
    for (int i = 0; i < polygon.size(); i++) {
        int j = (i + 1) % polygon.size();
        if (polygon[i].y <= pt.y) {
            if (polygon[j].y > pt.y && crossProduct(polygon[i], polygon[j], pt) > 0) {
                windingNumber++;
            }
        } else if (polygon[j].y <= pt.y && crossProduct(polygon[i], polygon[j], pt) < 0) {
            windingNumber--;
        }
    }
    return windingNumber != 0;
}

int main() {
    int N;
    while (std::cin >> N && N != 0) {
        std::vector<Point> window(N), curtain(4);
        for (int i = 0; i < N; i++) {
            std::cin >> window[i].x >> window[i].y;
        }
        for (int i = 0; i < 4; i++) {
            std::cin >> curtain[i].x >> curtain[i].y;
        }

        int totalArea = polygonArea(window);
        if (isInsidePolygon(curtain[0], window) &&
            isInsidePolygon(curtain[1], window) &&
            isInsidePolygon(curtain[2], window) &&
            isInsidePolygon(curtain[3], window)) {
            std::cout << "0\n";
        } else {
            int curtainArea = polygonArea(curtain);
            int uncoveredArea = totalArea - curtainArea;
            std::cout << uncoveredArea << "\n";
        }
    }

    return 0;
}