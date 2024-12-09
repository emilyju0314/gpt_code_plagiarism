#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> w(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> w[i];
    }

    vector<int> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    vector<long long> prefix_sum(n, 0);
    prefix_sum[0] = g[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + g[i];
    }

    auto check = [&](int l, int r) {
        long long remaining_gas = prefix_sum[r] - prefix_sum[l] + g[l]; // gas available at starting city
        long long total_cost = 0;
        for (int i = l; i < r; i++) {
            total_cost += w[i] * min(remaining_gas, 1LL); // consider taking gas at each city
            remaining_gas = max(remaining_gas - 1, 0LL); // consume 1 liter of gas for 1 km
        }
        return total_cost <= k; // check if total cost is within budget
    };

    int max_beauty = 0;
    for (int start = 0; start < n; start++) {
        int lo = start, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (check(start, mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        max_beauty = max(max_beauty, lo - start + 1);
    }

    cout << max_beauty << endl;

    return 0;
}