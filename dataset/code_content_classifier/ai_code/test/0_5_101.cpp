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
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        string colors;
        cin >> colors;

        int min_value = 1;
        int max_value = n;
        bool possible = true;

        for (int i = 0; i < n && possible; i++) {
            if (colors[i] == 'R') {
                max_value = min(max_value, a[i]);
            } else {
                min_value = max(min_value, a[i]);
            }

            if (max_value < min_value) {
                possible = false;
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