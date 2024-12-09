#include <iostream>

using namespace std;

int main() {
    long long k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;

    if (x >= y) {
        if (y + t*x <= r || (y - x >= l && y - x + t*x >= l)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        long long diff = y - x;
        if (t*x + diff <= r || (diff >= l && t*x + diff >= l) || (diff >= l && t*x <= r)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}