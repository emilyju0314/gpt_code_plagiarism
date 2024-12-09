#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a < b) {
        cout << "-1" << endl;
        return 0;
    }

    double x = 1.0;
    while (true) {
        double dist = sqrt(a * a + b * b); // distance from (0,0) to (a,b)
        int k = (int)(dist / x);
        double rem = dist - k * x; // remaining distance based on k and x

        if (fabs(rem - b) < 1e-9) {
            cout << fixed << setprecision(12) << x << endl;
            break;
        } 

        x += 1.0;
        if (x > a && x > b) {
            cout << "-1" << endl;
            break;
        }
    }

    return 0;
}