#include <iostream>

using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;

    string result = "";

    while (x > 0 && y > 0) {
        if (x >= y) {
            long long steps = x / y;
            for (int i = 0; i < steps; i++) {
                result += to_string(steps) + "A";
            }
            x %= y;
        } else if (y > x) {
            long long steps = y / x;
            for (int i = 0; i < steps; i++) {
                result += to_string(steps) + "B";
            }
            y %= x;
        }
    }

    if (x == 0 && y == 0) {
        cout << result << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}