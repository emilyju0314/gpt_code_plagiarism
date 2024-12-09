#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double pointToLineDistance(Point p, Point p1, Point p2) {
    double A = p.x - p1.x;
    double B = p.y - p1.y;
    double C = p2.x - p1.x;
    double D = p2.y - p1.y;

    double dot = A * C + B * D;
    double len_sq = C * C + D * D;
    double param = dot / len_sq;

    double closestX, closestY;

    if (param < 0) {
        closestX = p1.x;
        closestY = p1.y;
    } else if (param > 1) {
        closestX = p2.x;
        closestY = p2.y;
    } else {
        closestX = p1.x + param * C;
        closestY = p1.y + param * D;
    }

    return distance(p, {closestX, closestY});
}

int main() {
    int caseNum = 1;
    int N;
    while (cin >> N && N > 0) {
        vector<Point> vertices(N);
        for (int i = 0; i < N; i++) {
            cin >> vertices[i].x >> vertices[i].y;
        }

        double maxDistance = 0;
        for (int i = 0; i < N; i++) {
            maxDistance = max(maxDistance, pointToLineDistance(vertices[i], vertices[(i+1)%N], vertices[(i+2)%N]));
        }

        cout << "Case " << caseNum++ << ": " << fixed << maxDistance << endl;
    }
    return 0;
}