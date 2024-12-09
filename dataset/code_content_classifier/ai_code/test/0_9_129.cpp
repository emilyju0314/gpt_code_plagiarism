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

        int ans = 0;
        for (int i = n-1; i >= 0; i--) {
            if (a[i] > (n - i)) {
                ans += a[i] - (n - i);
                a[i] = n - i;
            }
        }

        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != i+1) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}