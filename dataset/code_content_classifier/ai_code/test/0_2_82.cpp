#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> prefix(n, 0);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + a[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        int min_cost = INT_MAX;
        if (l == r) {
            min_cost = 0;
        } else {
            min_cost = prefix[r-1] - prefix[l-1] + (r - l) * (k - 1) + a[l-1];
        }

        cout << min_cost << endl;
    }

    return 0;
}