#include <iostream>
#include <vector>

using namespace std;

struct Point {
    long long x, y;
};

long long cross_product(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

double calc_area(vector<Point>& points) {
    double area = 0.0;
    for (int i = 0; i < points.size(); i++) {
        Point p1 = points[i], p2 = points[(i + 1) % points.size()];
        area += p1.x * p2.y - p1.y * p2.x;
    }
    return abs(area) / 2.0;
}

long long count_integer_points(vector<Point>& points) {
    long long count = 0;
    for (int i = 0; i < points.size(); i++) {
        Point p1 = points[i], p2 = points[(i + 1) % points.size()];
        count += abs(__gcd(p1.x - p2.x, p1.y - p2.y));
    }
    return (count - points.size()) / 2 + 1;
}

int main() {
    int n;
    cin >> n;

    vector<Point> vertices(n);
    for (int i = 0; i < n; i++) {
        cin >> vertices[i].x >> vertices[i].y;
    }

    double total_area = calc_area(vertices);
    double expected_value = 0.0;

    for (int i = 0; i < n; i++) {
        vector<Point> current_polygon;
        current_polygon.push_back(vertices[i]);

        for (int j = i + 1; j < n; j++) {
            current_polygon.push_back(vertices[j]);
            double current_polygon_area = calc_area(current_polygon);
            long long num_integer_points = count_integer_points(current_polygon);
            expected_value += current_polygon_area / total_area * num_integer_points;
        }
    }

    printf("%.10lf", expected_value);
    
    return 0;
}