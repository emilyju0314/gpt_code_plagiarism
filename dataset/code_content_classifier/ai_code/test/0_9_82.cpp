#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    vector<long long> prefix_sum(n, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i] = (i > 0 ? prefix_sum[i-1] : 0) + cost[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        long long ans = 0;
        if (r - l > 0) {
            ans += prefix_sum[r - 1] - (l > 0 ? prefix_sum[l - 1] : 0);
            ans += (r - l) * 1LL * (k - 1);
        } else {
            ans += k - 1;
        }
        cout << ans << endl;
    }

    return 0;
}