#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> prefix_sum(n, 0);
    
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            prefix_sum[i] = prefix_sum[i-1] + a[i];
        } else {
            prefix_sum[i] = a[i];
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        long long total_cost = prefix_sum[r-1] - (l > 1 ? prefix_sum[l-2] : 0);
        long long min_cost = total_cost - (r - l + 1);

        cout << min_cost + 2 * (k - 1) << endl;
    }

    return 0;
}