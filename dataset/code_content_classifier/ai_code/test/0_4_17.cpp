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

        vector<int> mins(n + 1, 0);
        vector<int> maxs(n + 1, 0);

        int minval = a[n - 1];
        mins[n] = a[n - 1];
        for (int i = n - 1; i >= 1; i--) {
            minval = min(minval, a[i - 1]);
            mins[i] = minval;
        }

        int maxval = a[n - 1];
        maxs[n] = a[n - 1];
        for (int i = n - 1; i >= 1; i--) {
            maxval = max(maxval, a[i - 1]);
            maxs[i] = maxval;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i < n && ((maxs[i] > a[i - 1] && maxs[i + 1] > a[i - 1]) || (mins[i] > a[i - 1] && mins[i + 1] > a[i - 1]))) {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}