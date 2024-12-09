#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n, l, r, k;
    cin >> n >> l >> r >> k;

    long long sweetTooths = 0;
    long long candies = k;
    long long friend = l;
    bool possible = false;

    for (long long i = 0; i < n; i++) {
        if (friend == r && candies > 0) {
            possible = true;
            sweetTooths += min(candies, 2LL);
        } else {
            sweetTooths += min(candies, 1LL);
        }

        candies -= min(candies, 2LL);
        if (candies <= 0) break;

        friend++;
        if (friend > n) friend = 1;
    }

    if (possible) {
        cout << sweetTooths << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}