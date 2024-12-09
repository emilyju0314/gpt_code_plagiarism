#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        int minX = -100000, maxX = 100000, minY = -100000, maxY = 100000;

        for (int i = 0; i < n; i++) {
            int x, y, f1, f2, f3, f4;
            cin >> x >> y >> f1 >> f2 >> f3 >> f4;

            if (f1 == 0) {
                minX = max(minX, x - 1);
            }
            if (f2 == 0) {
                maxY = min(maxY, y + 1);
            }
            if (f3 == 0) {
                maxX = min(maxX, x + 1);
            }
            if (f4 == 0) {
                minY = max(minY, y - 1);
            }
        }

        if (minX <= maxX && minY <= maxY) {
            cout << "1 " << (minX + maxX) / 2 << " " << (minY + maxY) / 2 << endl;
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}