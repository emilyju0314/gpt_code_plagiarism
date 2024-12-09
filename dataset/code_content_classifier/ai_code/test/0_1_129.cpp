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

        sort(a.begin(), a.end());

        int operations = 0;
        int prev = 0;
        bool possible = true;

        for (int i = 0; i < n; i++) {
            if (a[i] <= i+1) {
                prev = max(prev, a[i]);
            } else {
                if (prev + operations >= a[i]) {
                    prev = max(prev, a[i]);
                } else {
                    possible = false;
                    break;
                }
            }
            if (i == n-1) {
                operations = prev-1;
            }
        }

        if (possible) {
            cout << operations << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}