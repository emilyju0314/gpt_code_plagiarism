#include <iostream>
using namespace std;

int countZeroBits(int n) {
    int count = 0;
    while(n > 0) {
        if((n & 1) == 0) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int l, r;
        cin >> l >> r;

        int msb = 1;
        while(msb <= r) {
            msb <<= 1;
        }
        msb >>= 1;

        if(msb == r) {
            cout << 0 << endl;
        } else {
            int diff = r - msb;
            if(msb / 2 >= l) {
                cout << diff + 1 << endl;
            } else {
                int count = countZeroBits(msb);
                cout << min(count, diff + 1) << endl;
            }
        }
    }

    return 0;
}