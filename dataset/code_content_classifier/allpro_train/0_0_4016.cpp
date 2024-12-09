#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 3) {
        cout << "No solution" << endl;
        return 0;
    }

    double angle = M_PI / n;
    double radius = 1000.0 / (2 * sin(angle)); // Radius of the circumcircle
    pair<double, double> center(1000000, 1000000); // Center of the circumcircle

    for (int i = 0; i < n; i++) {
        double x = center.first + radius * cos(2 * i * angle);
        double y = center.second + radius * sin(2 * i * angle);
        cout << x << " " << y << endl;
    }

    return 0;
}