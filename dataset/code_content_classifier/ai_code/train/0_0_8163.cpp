#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, U, R, D, L;
        cin >> n >> U >> R >> D >> L;

        bool possible = false;

        for (int i = 0; i < (1 << 4); i++) {
            int u = U, r = R, d = D, l = L;
            if (i & 1) u--, l--;
            if (i & 2) u--, r--;
            if (i & 4) r--, d--;
            if (i & 8) d--, l--;

            if (u >= 0 && r >= 0 && d >= 0 && l >= 0 && u <= n - 2 && r <= n - 2 && d <= n - 2 && l <= n - 2) {
                possible = true;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}