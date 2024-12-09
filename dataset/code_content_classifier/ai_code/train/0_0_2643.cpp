#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    int x, y, z;

    cin >> a >> b >> c;
    cin >> x >> y >> z;

    int totalSpheres = a + b + c;
    int totalNeeded = x + y + z;

    if (a >= x && b >= y && c >= z && totalSpheres >= totalNeeded) {
        cout << "Yes" << endl;
    } else if ((a + b >= x + y) && (a + c >= x + z) && (b + c >= y + z) && 
               (totalSpheres + 2*(min(min(x, y), z)) >= totalNeeded)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}