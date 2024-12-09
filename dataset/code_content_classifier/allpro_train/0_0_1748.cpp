#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, m;
        cin >> n >> m;

        bool satisfied = true;
        int prev_t = 0, prev_temp = m;

        for (int i = 0; i < n; i++) {
            int t, l, h;
            cin >> t >> l >> h;

            int diff = t - prev_t;
            int min_temp = prev_temp - diff;
            int max_temp = prev_temp + diff;

            prev_t = t;

            if (l <= max_temp && h >= min_temp) {
                min_temp = max(min_temp, l);
                max_temp = min(max_temp, h);
                prev_temp = (max_temp + min_temp) / 2;
            } else {
                satisfied = false;
            }
        }

        if (satisfied) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}