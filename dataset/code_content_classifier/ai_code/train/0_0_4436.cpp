#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int r, g, b, w;
        cin >> r >> g >> b >> w;

        int oddCount = 0;

        if (r % 2 == 1) {
            oddCount++;
        }
        if (g % 2 == 1) {
            oddCount++;
        }
        if (b % 2 == 1) {
            oddCount++;
        }
        if (w % 2 == 1) {
            oddCount++;
        }

        if (oddCount <= 1 || (r > 0 && g > 0 && b > 0)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}