#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;
            long long sum = 0;
            for (int i = l - 1; i < r; i++) {
                sum += a[i];
            }
            cout << sum << endl;
        } else {
            int x;
            cin >> x;
            do {
                next_permutation(a.begin(), a.end());
                x--;
            } while (x > 0);
        }
    }

    return 0;
}