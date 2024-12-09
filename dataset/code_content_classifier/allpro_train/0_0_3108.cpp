#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

struct Line {
    Point start, end;
};

bool pointInPolygon(const vector<Point>& polygon, const Point& point) {
    int numPoints = polygon.size();
    bool inside = false;
    for (int i = 0, j = numPoints - 1; i < numPoints; j = i++) {
        if (((polygon[i].y > point.y) != (polygon[j].y > point.y)) &&
            (point.x < (polygon[j].x - polygon[i].x) * (point.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}

double dotProduct(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

bool lineIntersect(const Line& line1, const Line& line2) {
    Point vec1 = {line1.end.x - line1.start.x, line1.end.y - line1.start.y};
    Point vec2 = {line2.end.x - line2.start.x, line2.end.y - line2.start.y};

    double crossProduct1 = line1.start.x * vec1.y - line1.start.y * vec1.x;
    double crossProduct2 = line2.start.x * vec2.y - line2.start.y * vec2.x;

    double crossProduct3 = line1.end.x * vec1.y - line1.end.y * vec1.x;
    double crossProduct4 = line2.end.x * vec2.y - line2.end.y * vec2.x;

    return (crossProduct1 * crossProduct2 < 0) && (crossProduct3 * crossProduct4 < 0);
}

int main() {
    int N, M, B;
    while (cin >> N >> M >> B && (N != 0 || M != 0 || B != 0)) {
        vector<Point> polygon(N);
        for (int i = 0; i < N; i++) {
            cin >> polygon[i].x >> polygon[i].y;
        }

        vector<Point> moveInstructions(M+1);
        for (int i = 1; i <= M; i++) {
            int Ti, VXi, VYi;
            cin >> Ti >> VXi >> VYi;
            moveInstructions[i] = {VXi, VYi};
        }

        vector<Line> bullets(B);
        for (int i = 0; i < B; i++) {
            int T, Xi, VX, VY, L;
            cin >> T >> Xi >> VX >> VY >> L;
            double endX = Xi - (L * VX / sqrt(VX*VX + VY*VY));
            double endY = - (L * VY / sqrt(VX*VX + VY*VY));
            bullets[i] = {{Xi, 0}, {endX, endY}};
        }

        int hits = 0;
        vector<double> collisionTimes;

        for (int i = 0; i < B; i++) {
            for (int j = 0; j <= M; j++) {
                Line playerLine = {{ moveInstructions[j].x, moveInstructions[j].y },
                                    { moveInstructions[j].x + polygon[0].x, moveInstructions[j].y + polygon[0].y }};

                Line bulletLine = bullets[i];
                if (lineIntersect(playerLine, bulletLine)) {
                    collisionTimes.push_back(i + (playerLine.start.x - bulletLine.start.x) / (bulletLine.end.x - bulletLine.start.x));
                    hits++;
                }
            }
        }

        cout << hits << endl;
        for (int i = 0; i < collisionTimes.size(); i++) {
            cout << fixed << setprecision(3) << collisionTimes[i] << endl;
        }
    }

    return 0;
}