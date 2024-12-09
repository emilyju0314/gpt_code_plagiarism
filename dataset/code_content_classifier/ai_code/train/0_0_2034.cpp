#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A, B, n;
    cin >> A >> B >> n;

    for (int i = 0; i < n; i++) {
        int l, t, m;
        cin >> l >> t >> m;

        int ans = -1;
        for (int r = l; ; r++) {
            int total_height = A + (r - 1) * B;
            int total_bites = (r - l + 1) * (A + total_height) / 2 - (l - 1) * A;
            int max_bites = min(m * t, t * (r - l + 1));

            if (total_bites <= max_bites) {
                ans = r;
            } else {
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}