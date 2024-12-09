#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int left_max = a[0];
        int right_min = a[n - 1];

        // Find the left maximum
        for (int i = 1; i < n; i++) {
            left_max = max(left_max, a[i]);
            if (left_max == a[i]) break;
        }

        // Find the right minimum
        for (int i = n - 2; i >= 0; i--) {
            right_min = min(right_min, a[i]);
            if (right_min == a[i]) break;
        }

        if (left_max != right_min) {
            cout << "NO" << endl;
        } else {
            for (int i = 1; i < n - 1; i++) {
                if (a[i] == left_max) {
                    cout << "YES" << endl;
                    cout << i << " " << 1 << " " << n - i - 1 << endl;
                    break;
                }
            }
        }
    }

    return 0;
}