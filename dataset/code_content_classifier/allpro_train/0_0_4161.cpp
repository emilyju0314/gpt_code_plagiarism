#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool comparePoints(const Point& p1, const Point& p2) {
    if (p1.x != p2.x) {
        return p1.x < p2.x;
    }
    return p1.y < p2.y;
}

int main() {
    int n;
    cin >> n;

    vector<vector<Point>> levels(200001); // maximum possible levels based on constraints

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        levels[max(x, y)].push_back({x, y});
    }

    for (int i = 0; i < levels.size(); i++) {
        sort(levels[i].begin(), levels[i].end(), comparePoints);
    }

    long long totalDistance = 0;
    Point currentPosition = {0, 0};

    for (int i = 1; i < levels.size(); i++) {
        for (const Point& keyPoint : levels[i]) {
            totalDistance += abs(currentPosition.x - keyPoint.x) + abs(currentPosition.y - keyPoint.y);
            currentPosition = keyPoint;
        }
    }

    cout << totalDistance << endl;

    return 0;
}