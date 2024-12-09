#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;

    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double r = (distance + R) / 2;
    
    double xap = x1 + (x2 - x1) * r / distance;
    double yap = y1 + (y2 - y1) * r / distance;
    
    cout << fixed << setprecision(15) << xap << " " << yap << " " << r << endl;

    return 0;
}