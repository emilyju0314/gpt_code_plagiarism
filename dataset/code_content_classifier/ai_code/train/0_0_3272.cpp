#include <iostream>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);

    double s = (a + b + c) / 2;
    double radius = 2 * sqrt(s * (s - a) * (s - b) * (s - c)) / (a + b + c);
    
    cout.precision(12);
    cout << fixed << radius << endl;

    return 0;
}