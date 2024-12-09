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

        int ans = 0;
        int negative_count = 0;
        int min_positive = INT_MAX;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] <= 0) {
                ans++;
                if (a[i] < 0) {
                    negative_count++;
                }
            } else {
                min_positive = min(min_positive, a[i]);
            }

            sum += a[i];
        }

        if (negative_count % 2 == 0 || sum <= 0) {
            ans++;
        } else {
            ans = ans;
        }

        cout << ans << endl;
    }

    return 0;
}