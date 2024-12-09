#include <iostream>

using namespace std;

int countBits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n >>= 1;
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        int msb_l = countBits(l);
        int msb_r = countBits(r);

        if (msb_l != msb_r) {
            cout << (1 << msb_r) - 1 << endl;
        } else {
            cout << r - (1 << msb_r) + 1 << endl;
        }
    }

    return 0;
}