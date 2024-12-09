#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.rbegin(), a.rend());

        int ans = a[0];

        for (int i = 1; i < n; i++) {
            if (a[0] % a[i] != 0) {
                ans += a[i];
                break;
            }
        }

        if (ans == a[0]) {
            for (int i = 1; i < n; i++) {
                if (ans % a[i] != 0) {
                    ans += a[i];
                    break;
                }
            }
        }

        if (ans == a[0]) {
            for (int i = 1; i < n; i++) {
                if (a[1] % a[i] != 0) {
                    ans += a[i];
                    break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}