#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<int> cost(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    vector<long long> prefix_sum(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + cost[i];
    }

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        long long ans = (prefix_sum[r] - prefix_sum[l-1]) - (r - l + 1);
        ans += (k - 1) * ((l - 1) == 0 ? 0 : cost[l - 1]) - ((l + 1) <= r ? k*2 - cost[l] - cost[l+1] : 0) - ((r + 1) <= n ? k*2 - cost[r-1] - cost[r] : 0);

        cout << ans << endl;
    }

    return 0;
}