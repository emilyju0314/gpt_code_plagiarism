#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        int diff = r - l;
        int msb = 0;
        while ((1 << msb) <= diff) {
            msb++;
        }
        int mask = (1 << msb) - 1;
        if ((l & mask) + (1 << (msb - 1)) <= r) {
            cout << r - (l | mask) << endl;
        } else {
            cout << r - l << endl;
        }
    }

    return 0;
}