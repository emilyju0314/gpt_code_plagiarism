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

        string colors;
        cin >> colors;

        int min_val = 1, max_val = n;
        bool possible = true;

        for (int i = 0; i < n; i++) {
            if (colors[i] == 'B') {
                min_val = max(min_val, a[i]);
            } else {
                max_val = min(max_val, a[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i] < min_val || a[i] > max_val) {
                possible = false;
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