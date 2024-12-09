#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double area(Point A, Point B, Point C) {
    double a = dist(B, C);
    double b = dist(A, C);
    double c = dist(A, B);
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    int n, Px, Py;
    cin >> n >> Px >> Py;

    Point P = {Px, Py};
    Point prev, first;
    cin >> first.x >> first.y;
    prev = first;

    double totalArea = 0;

    for (int i = 1; i < n; i++) {
        Point curr;
        cin >> curr.x >> curr.y;
        totalArea += area(P, prev, curr);
        prev = curr;
    }

    totalArea += area(P, prev, first);

    cout << fixed << totalArea << endl;

    return 0;
}