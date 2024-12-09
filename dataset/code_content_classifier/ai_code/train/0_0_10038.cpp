#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, w;

    while (true) {
        cin >> n >> w;

        if (n == 0 && w == 0) {
            break;
        }

        double maxRadius = 100; // Maximum possible radius

        for (int i = 0; i < n; i++) {
            int x, y, h;
            cin >> x >> y >> h;

            double minDist = min(min(x, y), min(100-x, 100-y)); // Calculate the minimum distance from the needle to the box corner
            minDist = min(minDist, h); // Update the minimum distance with respect to the height of the needle

            maxRadius = min(maxRadius, minDist / 2.0); // Update the maximum possible radius
        }

        double sideDist = min(min(w, 100-w), maxRadius); // Calculate the minimum distance to the side walls
        maxRadius = min(maxRadius, sideDist);

        cout << fixed;
        cout.precision(5);
        cout << maxRadius << endl;
    }

    return 0;
}