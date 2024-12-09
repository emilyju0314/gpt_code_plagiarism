#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, d;
    int n;
    cin >> a >> d >> n;

    double x = 0, y = 0;
    double side = a;
    int i = 1;
    while (i <= n) {
        if (x == 0 && y < side) {
            double delta = min(d, side - y);
            y += delta;
            if (y == side) {
                x += side;
                side += a;
            }
        } else if (x < side && y == side) {
            double delta = min(d, side - x);
            x += delta;
            if (x == side) {
                y += side;
                side += a;
            }
        } else if (x > 0 && y == side) {
            double delta = min(d, x);
            x -= delta;
        } else if (x == 0 && y > 0) {
            double delta = min(d, y);
            y -= delta;
        }
        
        cout << fixed << setprecision(10) << x << " " << y << endl;
        i++;
    }

    return 0;
}