#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, q;
vector<int> cnt(51);

int main() {
    cin >> n >> q;

    int cost = n * n;

    while (q--) {
        int t, l, r, v;
        cin >> t >> l >> r >> v;

        if (t == 1) {
            for (int i = l; i <= r; i++) {
                if (cnt[i] < v) {
                    cnt[i] = v;
                    cost -= 1;
                }
            }
        } else {
            for (int i = l; i <= r; i++) {
                if (cnt[i] > v) {
                    cnt[i] = v;
                    cost -= 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << cost << endl;

    return 0;
}