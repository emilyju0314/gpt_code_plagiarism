#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y, z;
};

struct Cone {
    Point apex;
    Point center;
    double radius;
};

double dotProduct(Point p1, Point p2) {
    return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}

double volumeCone(Cone cone) {
    return 1.0/3.0 * M_PI * cone.radius * cone.radius * distance(cone.apex, cone.center);
}

double calculateVolume(Point O, double R, Point P) {
    Point OP = {P.x - O.x, P.y - O.y, P.z - O.z};
    double t = dotProduct(OP, {O.x, O.y, O.z}) / dotProduct(OP, OP);

    Point Q = {O.x + t * (P.x - O.x), O.y + t * (P.y - O.y), O.z + t * (P.z - O.z)};

    double RQ = distance({O.x, O.y, O.z}, Q);
    double OQ = distance({O.x, O.y, O.z}, P);

    double R1 = RQ / OQ * R;
    double R2 = sqrt(R * R - R1 * R1);

    double volume1 = 1.0/3.0 * M_PI * R1 * R1 * RQ;
    double volume2 = 1.0/3.0 * M_PI * R2 * R2 * RQ;

    return volume1 + volume2;
}

int main() {
    Point apex, center, P;
    double R;

    cin >> apex.x >> apex.y >> apex.z;
    cin >> center.x >> center.y >> center.z >> R;
    cin >> P.x >> P.y >> P.z;

    Cone cone = {apex, center, R};

    double volume1 = calculateVolume(center, R, P);
    double volume2 = volumeCone(cone) - volume1;

    cout << fixed;
    cout.precision(6);
    cout << volume1 << " " << volume2 << endl;

    return 0;
}