#include <iostream>
#include <vector>

struct Point {
    int x, y;
};

bool isInsideRect(int x, int y, int x1, int y1, int x2, int y2) {
    return x >= x1 && x <= x2 && y >= y2 && y <= y1;
}

bool isInsidePolygon(const std::vector<Point>& polygon, int x, int y) {
    int crossings = 0;
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        int x1 = polygon[i].x;
        int y1 = polygon[i].y;
        int x2 = polygon[(i+1)%n].x;
        int y2 = polygon[(i+1)%n].y;

        // Check if point is inside rectangle defined by current and next point
        if (isInsideRect(x, y, x1, y1, x2, y2)) {
            return true;
        }

        // Count crossings of line defined by point and a point far outside
        if (((y1 > y) != (y2 > y)) && (x < (x2 - x1) * (y - y1) / (y2 - y1) + x1)) {
            crossings++;
        }
    }

    // If number of crossings is odd, point is inside polygon
    return crossings % 2 == 1;
}

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    int n;
    std::cin >> n;

    std::vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        std::cin >> polygon[i].x >> polygon[i].y;
    }

    int count = 0;
    for (int x = x1; x < x2; x++) {
        for (int y = y2; y < y1; y++) {
            if (isInsidePolygon(polygon, x, y)) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}