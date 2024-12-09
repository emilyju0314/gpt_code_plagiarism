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

    vector<int> prefix_sum(n);
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + (i > 1 ? a[i-1] - 1 : 0);
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        long long cost = prefix_sum[r-1] - prefix_sum[l-1] + a[l-1] - 1 + a[r-1] - k - 1;
        cout << cost << endl;
    }

    return 0;
}