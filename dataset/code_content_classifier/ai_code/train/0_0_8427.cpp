#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int c0 = 0, c1 = 0, c2 = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 3 == 0) {
                c0++;
            } else if (a[i] % 3 == 1) {
                c1++;
            } else {
                c2++;
            }
        }

        int target = n / 3;
        int moves = 0;

        while (c0 != target || c1 != target || c2 != target) {
            if (c0 > target) {
                int diff = c0 - target;
                moves += diff;
                c1 += diff;
                c0 = target;
            } else if (c1 > target) {
                int diff = c1 - target;
                moves += diff;
                c2 += diff;
                c1 = target;
            } else {
                int diff = c2 - target;
                moves += diff;
                c0 += diff;
                c2 = target;
            }
        }

        cout << moves << endl;
    }

    return 0;
}