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

        long long sum = 0;
        long long ans = 0;
        long long best = 0;

        for (int i = 0; i < n; i += 2) {
            sum += a[i];
            if (i + 1 < n) {
                ans = max(ans, 0LL + a[i+1] - a[i]);
                best = max(best, ans);
            }
            if (i + 2 < n) {
                ans = max(ans + a[i+2], 0LL + a[i+2] - a[i+1]);
                best = max(best, ans);
            }
        }

        cout << sum + best << endl;
    }

    return 0;
}