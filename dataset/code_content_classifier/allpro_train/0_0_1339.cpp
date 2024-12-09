#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l, r, Ql, Qr;
    cin >> n >> l >> r >> Ql >> Qr;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + weights[i-1];
    }

    long long result = LLONG_MAX;
    for (int i = 0; i <= n; i++) {
        long long left_cost = prefix_sum[i] * l + (prefix_sum[n] - prefix_sum[i]) * r;
        int left_items = i, right_items = n - i;
        if (left_items > right_items) {
            left_cost += (left_items - right_items - 1) * Ql;
        } else if (right_items > left_items) {
            left_cost += (right_items - left_items - 1) * Qr;
        }
        result = min(result, left_cost);
    }

    cout << result << endl;

    return 0;
}