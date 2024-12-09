#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> prefix_sum(n);
        prefix_sum[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + a[i];
        }

        int max_k = 0;
        long long prev_sum = 0;
        for (int k = 1; k <= n; k++) {
            bool valid = true;
            for (int i = k - 1; i < n; i++) {
                if (i > k - 1 && prefix_sum[i] - prefix_sum[i - k] <= prev_sum) {
                    valid = false;
                    break;
                }
                prev_sum = prefix_sum[i] - prefix_sum[i - k];
            }
            if (valid) {
                max_k = max(max_k, k);
            }
        }

        cout << max_k << endl;
    }

    return 0;
}