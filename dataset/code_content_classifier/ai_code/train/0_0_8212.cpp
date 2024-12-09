#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double xA, yA, xB, yB, xC, yC, xD, yD;

    while (cin >> xA >> yA >> xB >> yB >> xC >> yC >> xD >> yD) {
        double ABx = xB - xA;
        double ABy = yB - yA;
        double CDx = xD - xC;
        double CDy = yD - yC;

        double dotProduct = ABx * CDx + ABy * CDy;

        if (fabs(dotProduct) < 1e-10) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}