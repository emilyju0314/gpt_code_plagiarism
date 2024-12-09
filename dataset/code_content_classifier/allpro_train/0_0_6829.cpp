#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    int x, y;
};

struct Line {
    Point p1, p2;
};

bool isLeftTurn(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y) > 0;
}

Point intersection(const Line& l1, const Line& l2) {
    int x1 = l1.p1.x, y1 = l1.p1.y;
    int x2 = l1.p2.x, y2 = l1.p2.y;
    int x3 = l2.p1.x, y3 = l2.p1.y;
    int x4 = l2.p2.x, y4 = l2.p2.y;

    Point result;

    result.x = ((x1 * y2 - y1 * x2)*(x3 - x4) - ( x1 - x2 )*( x3 * y4 - y3 * x4 )) / (( x1 - x2 )*( y3 - y4 ) - ( y1 - y2 )*( x3 - x4 ));
    result.y = ((x1 * y2 - y1 * x2)*(y3 - y4) - ( y1 - y2 )*( x3 * y4 - y3 * x4 )) / (( x1 - x2 )*( y3 - y4 ) - ( y1 - y2 )*( x3 - x4 ));

    return result;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        Point start, end;
        std::cin >> start.x >> start.y;
        std::cin >> end.x >> end.y;

        std::vector<Line> lines(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> lines[i].p1.x >> lines[i].p1.y >> lines[i].p2.x >> lines[i].p2.y;
        }

        bool found = false;
        std::vector<Point> points;
        Point current = start;

        while (current.x != end.x || current.y != end.y) {
            bool pathFound = false;
            Line shortestLine;
            double shortestDist = 1e9;

            for (const auto& line : lines) {
                if (isLeftTurn(line.p1, line.p2, current)) {
                    if (isLeftTurn(current, end, line.p1)) {
                        Line edge;
                        edge.p1 = current;
                        edge.p2 = end;

                        Point intersect = intersection(line, edge);
                        double dist = std::sqrt((intersect.x - current.x)*(intersect.x - current.x) + (intersect.y - current.y)*(intersect.y - current.y));

                        if (dist < shortestDist) {
                            shortestDist = dist;
                            shortestLine = line;
                            pathFound = true;
                        }
                    }
                }
            }

            if (!pathFound) {
                break;
            }

            points.push_back(intersection(shortestLine, {current, end}));
            current = intersection(shortestLine, {current, end});
            if (current.x == end.x && current.y == end.y) {
                found = true;
            }
        }

        if (found) {
            for (const auto& point : points) {
                std::cout << point.x << " " << point.y << std::endl;
            }
            std::cout << "0" << std::endl;
        } else {
            std::cout << "-1" << std::endl;
        }
    }

    return 0;
}