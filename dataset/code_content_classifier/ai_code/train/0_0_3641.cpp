#include <iostream>

using namespace std;

int main() {
    int w, h, k;
    cin >> w >> h >> k;

    int gildedCells = 0;
    for (int i = 1; i <= k; i++) {
        gildedCells += 2 * w + 2 * h - 4 * (i - 1);
    }

    cout << gildedCells << endl;

    return 0;
}