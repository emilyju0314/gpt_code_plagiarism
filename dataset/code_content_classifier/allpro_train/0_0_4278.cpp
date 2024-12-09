#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b - a == c - b && d - c == c - b) {
        cout << d + (d - c) << endl;
    } else if (b / a == c / b && d / c == c / b && b % a == 0 && c % b == 0) {
        cout << d * (d / c) << endl;
    } else {
        cout << 42 << endl;
    }

    return 0;
}