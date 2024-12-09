#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;

        int white_cells = k1 + k2;
        int black_cells = 2 * n - white_cells;

        if (white_cells >= 2 * w && black_cells >= 2 * b) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}