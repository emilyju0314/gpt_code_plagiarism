#include <iostream>

using namespace std;

long long reverseAndAdd(long long num) {
    long long rev = 0;
    while(num > 0) {
        rev = (rev << 1) | (num & 1);
        num >>= 1;
    }
    return rev;
}

int main() {
    long long x, y;
    cin >> x >> y;

    while(y > x) {
        if(y % 2 == 0) {
            y /= 2;
        } else {
            y = (y + 1) / 2;
        }

        if(y >= x) {
            y = reverseAndAdd(y);
        }
    }

    if(x == y) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}