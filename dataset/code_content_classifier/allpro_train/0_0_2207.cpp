#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long l, r, k;
    cin >> l >> r >> k;

    long long x = l, f_min = 0;
    for (int i = 0; i < 60; i++) {
        if ((x | (1LL << i)) > r) {
            f_min |= (1LL << i);
            break;
        }
    }

    cout << f_min << endl;

    // The cardinality of the set should be at least 2 to achieve the minimum f(S)
    if (k == 1) {
        cout << 2 << endl;
        cout << (f_min | (1LL << __builtin_ctzll(f_min))) << " " << f_min << endl;
    } else {
        cout << min(k, 2LL) << endl;
        cout << (f_min | (1LL << __builtin_ctzll(f_min))) << " " << f_min << endl;
    }

    return 0;
}