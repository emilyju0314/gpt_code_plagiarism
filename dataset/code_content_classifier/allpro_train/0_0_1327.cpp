#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = (i % 2 == 0) ? a[i] : -a[i];
        }

        long long total = 0;
        for (int i = 0; i < n-1; i++) {
            total += diff[i];
        }

        cout << total << endl;

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--;

            for (int i = l; i <= r; i++) {
                total -= diff[i];
            }

            swap(diff[l], diff[r]);

            for (int i = l; i <= r; i++) {
                total += diff[i];
            }

            cout << total << endl;
        }
    }

    return 0;
}