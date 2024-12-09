#include <iostream>
using namespace std;

int main() {
    int x1, x2, a, b;
    cin >> x1 >> x2 >> a >> b;

    if (a <= 0 && 0 <= b) {
        cout << "DRAW" << endl;
    } else if (x1 < x2 && x1 + a <= x2 && x2 <= x1 + b) {
        cout << "SECOND" << endl;
    } else if (x2 < x1 && x2 + a <= x1 && x1 <= x2 + b) {
        cout << "FIRST" << endl;
        cout << x1 << endl;
    } else if (x1 < x2) {
        cout << "FIRST" << endl;
        int x = min(x2 - 1, x1 + b);
        cout << x << endl;
    } else {
        cout << "SECOND" << endl;
    }

    return 0;
}