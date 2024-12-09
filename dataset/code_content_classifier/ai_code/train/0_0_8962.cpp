#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, r1, x2, y2, r2;
    double distance, angle, area;
    
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    
    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    if (distance >= r1 + r2) {
        cout << 0.0 << endl;
        return 0;
    }
    
    if (r2 > r1) {
        swap(r1, r2);
        swap(x1, x2);
        swap(y1, y2);
    }
    
    if (distance <= r1 - r2) {
        cout << fixed << 3.14159265358979323846 * pow(r2, 2) << endl;
        return 0;
    }
    
    angle = 2 * acos((pow(r1, 2) + pow(distance, 2) - pow(r2, 2)) / (2 * r1 * distance));
    area = 0.5 * pow(r1, 2) * (angle - sin(angle)) + 0.5 * pow(r2, 2) * (M_PI - angle + sin(angle));

    cout << fixed << area << endl;
    
    return 0;
}