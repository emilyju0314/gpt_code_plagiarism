#include <iostream>

using namespace std;

int main() {
    int a, b, m;
    cin >> a >> b >> m;
    
    int vx, vy, vz;
    cin >> vx >> vy >> vz;
    
    double x0, z0;
    x0 = m * vx / vy;
    z0 = m * vz / vy;
    
    cout << fixed;
    cout.precision(10);
    cout << x0 << " " << z0 << endl;
    
    return 0;
}