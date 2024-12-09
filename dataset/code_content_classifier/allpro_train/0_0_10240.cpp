#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int x1 = -1, x2 = -1;

        if (a < c) {
            x1 = 1;
        }

        if (a * b > c) {
            x2 = b;
        }

        cout << x1 << " " << x2 << "\n";
    }

    return 0;
}