#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, idx;

    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

bool isRectangle(const vector<Point>& points) {
    if(points.size() != 4) return false;

    int countX = 0, countY = 0;
    for(int i = 1; i < 4; i++) {
        if(points[i].x == points[i-1].x) countX++;
        if(points[i].y == points[i-1].y) countY++;
    }

    return (countX == 2 && countY == 2);
}

bool isSquare(const vector<Point>& points) {
    if(points.size() != 4) return false;

    int dist1 = (points[0].x - points[1].x)*(points[0].x - points[1].x) + (points[0].y - points[1].y)*(points[0].y - points[1].y);
    int dist2 = (points[0].x - points[2].x)*(points[0].x - points[2].x) + (points[0].y - points[2].y)*(points[0].y - points[2].y);
    int dist3 = (points[0].x - points[3].x)*(points[0].x - points[3].x) + (points[0].y - points[3].y)*(points[0].y - points[3].y);

    return (dist1 == dist2 && dist2 == dist3);
}

int main() {
    vector<Point> points(8);
    for(int i = 0; i < 8; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].idx = i + 1;
    }

    sort(points.begin(), points.end());

    do {
        vector<Point> squarePoints, rectanglePoints;
        for(int mask = 0; mask < (1 << 8); mask++) {
            if(__builtin_popcount(mask) != 4) continue;

            squarePoints.clear();
            rectanglePoints.clear();

            for(int i = 0; i < 8; i++) {
                if(mask & (1 << i)) squarePoints.push_back(points[i]);
                else rectanglePoints.push_back(points[i]);
            }

            if(isSquare(squarePoints) && isRectangle(rectanglePoints)) {
                cout << "YES" << endl;
                for(const auto& point : squarePoints) {
                    cout << point.idx << " ";
                }
                cout << endl;
                for(const auto& point : rectanglePoints) {
                    cout << point.idx << " ";
                }
                cout << endl;
                return 0;
            }
        }
    } while(next_permutation(points.begin(), points.end()));

    cout << "NO" << endl;
    return 0;
}