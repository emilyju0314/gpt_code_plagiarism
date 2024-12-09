#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x, y, a, b;
        cin >> x >> y >> a >> b;

        if (a == b) {
            if (x == y) {
                cout << x / a << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            if (x < y) {
                swap(x, y);
            }
            long long l = 0, r = min(x/a, y/b), ans = 0;

            // Binary search to find the maximum number of gift sets
            while (l <= r) {
                long long mid = (l + r) / 2;
                long long red = x - a * mid;
                long long blue = y - b * mid;

                if (red >= 0 && blue >= 0) {
                    ans = max(ans, mid);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}