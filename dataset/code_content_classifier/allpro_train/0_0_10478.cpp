#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    int N;
    cin >> N;

    vector<Point> points;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    double answer = 1e9;
    for (int i = 0; i < N; i++) {
        Point p1 = points[i];
        Point p2 = points[(i + 1) % N];
        Point p3 = points[(i + 2) % N];

        double side = distance(p1, p2) + distance(p2, p3) + distance(p3, p1);
        answer = min(answer, side);
    }

    double side_length = answer / 3 * sqrt(3);
    cout << fixed;
    cout.precision(8);
    cout << side_length << endl;

    return 0;
}