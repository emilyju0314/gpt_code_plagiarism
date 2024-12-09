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

    vector<pair<int, int>> students(q);
    for (int i = 0; i < q; i++) {
        cin >> students[i].first >> students[i].second;
    }

    vector<long long> prefix_sum(n);
    prefix_sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    for (int i = 0; i < q; i++) {
        int l = students[i].first - 1;
        int r = students[i].second - 1;

        long long total_cost = prefix_sum[r] - (l > 0 ? prefix_sum[l - 1] : 0);

        if (l > 0) {
            total_cost -= k * (r - l + 1);
            total_cost += 2 * (k - 1);
        } else {
            total_cost -= (k - 1);
        }

        cout << total_cost << endl;
    }

    return 0;
}