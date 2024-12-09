#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long reverseAndAdd(long long n) {
    string binary = bitset<64>(n).to_string();
    reverse(binary.begin(), binary.end());
    binary.erase(0, binary.find_first_not_of('0'));
    return stoll(binary, 0, 2);
}

bool canBeTurnedInto(long long x, long long y) {
    if (x == y) {
        return true;
    }
    while (x < y) {
        if (y % 2 == 0) {
            y /= 2;
        } else {
            y = (y + 1) / 2;
        }
    }
    return x == y;
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