#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
    int z;
};

// Function to calculate cross product of two vectors
Point crossProduct(Point a, Point b) {
    Point c;
    c.x = a.y * b.z - a.z * b.y;
    c.y = a.z * b.x - a.x * b.z;
    c.z = a.x * b.y - a.y * b.x;
    return c;
}

// Function to check if a point is inside the triangle formed by three vertices
bool isInsideTriangle(Point p, Point a, Point b, Point c) {
    Point ab = {b.x - a.x, b.y - a.y, b.z - a.z};
    Point ac = {c.x - a.x, c.y - a.y, c.z - a.z};
    Point ap = {p.x - a.x, p.y - a.y, p.z - a.z};

    Point normal = crossProduct(ab, ac);
    Point normal1 = crossProduct(ab, ap);
    Point normal2 = crossProduct(ac, ap);

    if (normal.x * normal1.x >= 0 && normal.y * normal1.y >= 0 && normal.z * normal1.z >= 0 &&
        normal.x * normal2.x >= 0 && normal.y * normal2.y >= 0 && normal.z * normal2.z >= 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Point advance, enemy, vertex1, vertex2, vertex3;
    
    // Input coordinates
    cin >> advance.x >> advance.y >> advance.z;
    cin >> enemy.x >> enemy.y >> enemy.z;
    cin >> vertex1.x >> vertex1.y >> vertex1.z;
    cin >> vertex2.x >> vertex2.y >> vertex2.z;
    cin >> vertex3.x >> vertex3.y >> vertex3.z;

    // Check if enemy is inside the barrier
    if (isInsideTriangle(enemy, vertex1, vertex2, vertex3)) {
        cout << "MISS" << endl;
    } else {
        cout << "HIT" << endl;
    }

    return 0;
}