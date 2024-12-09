#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Point {
    double x, y;
};

bool checkCollinear(Point p1, Point p2, Point p3) {
    return ((p3.y - p1.y) * (p2.x - p1.x) == (p2.y - p1.y) * (p3.x - p1.x));
}

Point calculateFourthPoint(Point p1, Point p2, Point p3) {
    Point p4;
    p4.x = 2 * p2.x - p1.x;
    p4.y = 2 * p2.y - p1.y;
    return p4;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        Point p1, p2, p3;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

        vector<Point> vertices;
        vertices.push_back(p1);
        vertices.push_back(p2);
        vertices.push_back(p3);
        
        if (!checkCollinear(p1, p2, p3)) {
            Point p4 = calculateFourthPoint(p1, p2, p3);
            vertices.push_back(p4);

            cout << "YES" << endl;
            for (int i = 0; i < 4; i++) {
                cout << fixed << setprecision(9) << vertices[i].x << " " << vertices[i].y << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}