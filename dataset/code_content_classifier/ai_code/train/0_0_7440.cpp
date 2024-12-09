#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
};

bool isPointOnSegment(Point p, Point a, Point b) {
    if (min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
        min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y)) {
        return true;
    }
    return false;
}

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double minStopLength(vector<Point>& segments, vector<Point>& valves, Point source, Point repair) {
    double result = 0;
    for (Point seg : segments) {
        result += distance(Point(seg.x, seg.y), Point(seg.x, seg.y));
    }
    for (Point val : valves) {
        if (isPointOnSegment(val, source, repair)) {
            return -1;
        }
    }
    return result - distance(source, repair);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Point> segments(N);
    for (int i = 0; i < N; i++) {
        cin >> segments[i].x >> segments[i].y >> segments[i].x >> segments[i].y;
    }

    vector<Point> valves(M);
    for (int i = 0; i < M; i++) {
        cin >> valves[i].x >> valves[i].y;
    }

    Point source, repair;
    cin >> source.x >> source.y;
    cin >> repair.x >> repair.y;

    double result = minStopLength(segments, valves, source, repair);
    cout << fixed << result << endl;

    return 0;
}