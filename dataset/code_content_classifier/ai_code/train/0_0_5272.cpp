#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

struct Point {
    double x, y;

    Point(): x(0), y(0) {}
    Point(double x, double y): x(x), y(y) {}

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    Point operator*(double c) const {
        return Point(x * c, y * c);
    }

    double cross(const Point& other) const {
        return x * other.y - y * other.x;
    }
};

int main() {
    string cmd;
    while (cin >> cmd && cmd != "end") {
        Point center(0, 0);
        double area = 0;

        Point cur(0, 0), start(0, 0);
        while (cin >> cmd && cmd != "close") {
            if (cmd == "start") {
                cin >> start.x >> start.y;
                cur = start;
            } else if (cmd == "line") {
                Point next;
                cin >> next.x >> next.y;
                area += cur.cross(next);
                center = center + (cur + next) * cur.cross(next);
                cur = next;
            } else { // arc
                Point next;
                double r;
                cin >> next.x >> next.y >> r;
                Point vec1 = cur - next;
                Point vec2 = Point(-vec1.y, vec1.x) * r / hypot(vec1.x, vec1.y);
                double angle = atan2(vec1.cross(vec2), vec1.x * vec2.x + vec1.y * vec2.y);
                curve = angle * r;
                center = center + (cur + next) * curve / 2;
                area += cur.cross(next) + r * r * angle;
                cur = next;
            }
        }

        area += cur.cross(start);
        center = center + (cur + start) * cur.cross(start);

        if (area < 0) {
            area = -area;
            center = center * -1;
        }

        cout << fixed << setprecision(5) << center.x / (3 * area) << " " << center.y / (3 * area) << " " << (area > 0 ? "+" : "-") << endl;
    }

    return 0;
}