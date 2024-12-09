#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string W1, W2;
    int d1, l1, d2, l2;
    
    cin >> W1 >> d1 >> l1;
    cin >> W2 >> d2 >> l2;
    
    // Convert degrees to radians
    double rad_d1 = d1 * M_PI / 180;
    double rad_d2 = d2 * M_PI / 180;
    
    // Calculate the position of each worm on the tetrahedron
    double x1, y1, x2, y2;
    
    if (W1 == "BC") {
        x1 = 0;
        y1 = l1 * sin(rad_d1);
    } else if (W1 == "CD") {
        x1 = l1 * cos(rad_d1);
        y1 = 0;
    } else {
        x1 = l1 * cos(M_PI / 3 - rad_d1);
        y1 = l1 * sin(M_PI / 3 - rad_d1);
    }
    
    if (W2 == "BC") {
        x2 = 0;
        y2 = l2 * sin(rad_d2);
    } else if (W2 == "CD") {
        x2 = l2 * cos(rad_d2);
        y2 = 0;
    } else {
        x2 = l2 * cos(M_PI / 3 - rad_d2);
        y2 = l2 * sin(M_PI / 3 - rad_d2);
    }
    
    // Check if the worms are on the same face of the tetrahedron
    if ((x1 < 0 && x2 < 0) || (y1 < 0 && y2 < 0) || (x1 > 0 && y2 > 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}