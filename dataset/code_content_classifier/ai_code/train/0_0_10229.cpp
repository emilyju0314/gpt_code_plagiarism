#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, t_a, t_b, k;
    cin >> n >> m >> t_a >> t_b >> k;

    vector<long long> a(n), b(m);
    vector<long long> prefix_sum_b(m+1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= m; i++) {
        prefix_sum_b[i] = b[i-1] + t_b;
    }

    long long ans = -1;
    if (k >= min(n, m)) {
        ans = -1;
    } else {
        for (int cancel_a = 0; cancel_a <= k; cancel_a++) {
            int cancel_b = k - cancel_a;

            int start_b = lower_bound(b.begin(), b.end(), a[cancel_a] + t_a) - b.begin();
            if (start_b + cancel_b <= m) {
                ans = max(ans, prefix_sum_b[start_b + cancel_b]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}