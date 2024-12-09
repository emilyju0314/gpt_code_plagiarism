#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

int main() {
    double r, h;
    cin >> r >> h;
    
    double x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;
    
    double dist = 0.0;
    
    // Check different cases
    if (z1 == 0 && z2 == 0) {
        dist = distance(x1, y1, z1, x2, y2, z2);
    } else if (z1 == 0 || z2 == 0) {
        double baseDist = distance(x1, y1, z1, x2, y2, 0);
        double sideDist = h - min(z1, z2);
        dist = baseDist + sideDist;
    } else {
        double sideDist = distance(x1, y1, z1, x2, y2, z2);
        double theta = atan(r / h);
        
        double arcDist = sqrt(pow(sideDist, 2) + pow(2 * M_PI * r * theta, 2));
        dist = min(arcDist, sideDist + h);
    }
    
    cout << fixed << setprecision(9) << dist << endl;
    
    return 0;
}