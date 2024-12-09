#include <iostream>
using namespace std;

long long reverse(long long n) {
    long long rev = 0;
    while (n > 0) {
        rev = (rev << 1) | (n & 1);
        n >>= 1;
    }
    return rev;
}

bool canBeTurnedInto(long long x, long long y) {
    while (y >= x) {
        if (y == x) {
            return true;
        }
        if (y % 2 == 0) {
            y /= 2;
        } else {
            y = (y + 1) / 2;
        }
    }
    return false;
}

int main() {
    long long x, y;
    cin >> x >> y;

    if (canBeTurnedInto(x, y)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}