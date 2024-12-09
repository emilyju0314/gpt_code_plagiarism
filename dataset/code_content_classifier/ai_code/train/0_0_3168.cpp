#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int q;
    cin >> q;

    vector<int> a(n * k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            a[i * n + j] = b[j];
        }
    }

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            for (int j = l - 1; j < r; j++) {
                a[j] = x;
            }
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            int min_val = INT_MAX;
            for (int j = l - 1; j < r; j++) {
                min_val = min(min_val, a[j]);
            }
            cout << min_val << endl;
        }
    }

    return 0;
}