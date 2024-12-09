#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, c, q;
        cin >> n >> c >> q;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        while (q--) {
            int i, j;
            cin >> i >> j;

            // Determine the range of the permutation affected by the operation
            int l = i, r = i;
            for (int k = 0; k < n; k++) {
                if (p[k] < p[i - 1]) {
                    l = min(l, k + 1);
                    r = max(r, k + 1);
                }
            }

            // Check if the j-th permutation exists
            if ((r - l) > c) {
                cout << -1 << endl;
            } else {
                // Calculate the value at the i-th position in the j-th permutation
                if (j <= l || j > r) {
                    cout << j << endl;
                } else {
                    cout << (l + r - j) << endl;
                }
            }
        }
    }

    return 0;
}