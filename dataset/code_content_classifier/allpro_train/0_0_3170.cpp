#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y, z, u, v;
};

double dotProduct(Point a, Point b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.u * b.u + a.v * b.v;
}

double length(Point a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.u * a.u + a.v * a.v);
}

bool isGood(Point a, Point b, Point c) {
    Point ab = {b.x - a.x, b.y - a.y, b.z - a.z, b.u - a.u, b.v - a.v};
    Point ac = {c.x - a.x, c.y - a.y, c.z - a.z, c.u - a.u, c.v - a.v};
    
    double dotAB = dotProduct(ab, ac);
    double lenAB = length(ab);
    double lenAC = length(ac);
    
    double angle = acos(dotAB / (lenAB * lenAC));
    
    return angle >= M_PI_2;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].z >> points[i].u >> points[i].v;
    }
    
    vector<int> goodPoints;
    for (int i = 0; i < n; i++) {
        bool isPointGood = true;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) {
                        if (!isGood(points[i], points[j], points[k])) {
                            isPointGood = false;
                            break;
                        }
                    }
                }
            }
            if (!isPointGood) {
                break;
            }
        }
        if (isPointGood) {
            goodPoints.push_back(i + 1);
        }
    }
    
    cout << goodPoints.size() << endl;
    for (int idx : goodPoints) {
        cout << idx << endl;
    }
    
    return 0;
}