#include <iostream>

using namespace std;

int main() {
    int x, y, z;
    int a, b, c;

    // Input the number of grapes each person wants to eat and the number of grapes in the box
    cin >> x >> y >> z;
    cin >> a >> b >> c;

    // Check if there are enough grapes of each type to make everyone happy
    if (a >= x && (a - x + b) >= y && (a + b - x - y + c) >= z) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}