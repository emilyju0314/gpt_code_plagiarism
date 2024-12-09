#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        double area = 0.0;
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2, r;
            cin >> x1 >> y1 >> x2 >> y2 >> r;

            double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
            double b = r;
            double c = r;

            double s = (a + b + c) / 2.0;
            double triangleArea = sqrt(s * (s - a) * (s - b) * (s - c));

            area += triangleArea;
        }

        cout << fixed;
        cout.precision(5);
        cout << area << endl;
    }

    return 0;
}