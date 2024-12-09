#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int w, h, alpha;
    cin >> w >> h >> alpha;

    double radians = alpha * M_PI / 180.0;

    double x = min(w/2.0, h/2.0);
    double y = max(w/2.0, h/2.0);

    if (x * 2.0 > y) {
        double angle = atan((y - x) / (x + y));
        double area = x * y + (x*x + y*y - x*y) * angle;
        cout << area << endl;
    } else {
        double area = x * y;
        cout << area << endl;
    }

    return 0;
}