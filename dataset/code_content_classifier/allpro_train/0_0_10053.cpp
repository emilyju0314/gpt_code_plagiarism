#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int l, r;
        cin >> l >> r;

        // Find x and y such that l ≤ x, y ≤ r, x ≠ y and x divides y
        // We can simply return l and 2 * l, as in this case x divides y
        cout << l << " " << 2 * l << endl;
    }

    return 0;
}