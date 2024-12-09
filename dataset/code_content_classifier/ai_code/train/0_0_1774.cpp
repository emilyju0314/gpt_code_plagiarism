#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int A, B, n;
    cin >> A >> B >> n;

    for (int i = 0; i < n; i++) {
        int l, t, m;
        cin >> l >> t >> m;

        int start = l, end = 1e6;
        int ans = -1;

        while (start <= end) {
            int mid = (start + end) / 2;
            int sum = (2 * A + (2 * l + (mid - l) * B)) * (mid - l + 1) / 2 - (A + (mid - 1) * B) * (mid - l + 1);
            
            if (sum <= t * m) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}