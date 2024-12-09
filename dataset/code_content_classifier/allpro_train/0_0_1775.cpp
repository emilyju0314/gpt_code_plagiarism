#include <iostream>

using namespace std;

int main() {
    int a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

    // Check if the paintings can be placed on the board
    if ((a2 + a3 <= a1 && max(b2, b3) <= b1) ||
        (a2 + b3 <= a1 && max(b2, a3) <= b1) ||
        (b2 + a3 <= a1 && max(a2, b3) <= b1) ||
        (b2 + b3 <= a1 && max(a2, a3) <= b1) ||
        (a2 + a3 <= b1 && max(b2, b3) <= a1) ||
        (a2 + b3 <= b1 && max(b2, a3) <= a1) ||
        (b2 + a3 <= b1 && max(a2, b3) <= a1) ||
        (b2 + b3 <= b1 && max(a2, a3) <= a1)
    ) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}