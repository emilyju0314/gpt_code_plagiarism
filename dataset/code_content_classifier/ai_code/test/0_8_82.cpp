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

    vector<long long> prefix_sum(n, 0);
    for (int i = 1; i < n-1; i++) {
        prefix_sum[i] = prefix_sum[i-1] + a[i+1] - a[i-1] - 2;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        long long ans;
        if (l == r) {
            ans = k-1;
        } else {
            ans = prefix_sum[r-2] - prefix_sum[l-1] + a[l] - 2 + k - a[r-1] - 1;
        }
        cout << ans << endl;
    }

    return 0;
}