#include <iostream>
#include <vector>
#include <algorithm>

struct Segment {
    int x1, y1, x2, y2;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Segment> segments(n);
    std::vector<int> x_points, y_points;

    for (int i = 0; i < n; i++) {
        std::cin >> segments[i].x1 >> segments[i].y1 >> segments[i].x2 >> segments[i].y2;
        x_points.push_back(segments[i].x1);
        x_points.push_back(segments[i].x2);
        y_points.push_back(segments[i].y1);
        y_points.push_back(segments[i].y2);
    }

    std::sort(x_points.begin(), x_points.end());
    std::sort(y_points.begin(), y_points.end());

    int max_length = 0;
    for (int i = 0; i < n; i++) {
        int x1 = std::lower_bound(x_points.begin(), x_points.end(), segments[i].x1) - x_points.begin();
        int x2 = std::lower_bound(x_points.begin(), x_points.end(), segments[i].x2) - x_points.begin();
        int y1 = std::lower_bound(y_points.begin(), y_points.end(), segments[i].y1) - y_points.begin();
        int y2 = std::lower_bound(y_points.begin(), y_points.end(), segments[i].y2) - y_points.begin();

        max_length += std::abs(x_points[x2] - x_points[x1]) + std::abs(y_points[y2] - y_points[y1]);
    }

    std::cout << max_length << std::endl;

    return 0;
}