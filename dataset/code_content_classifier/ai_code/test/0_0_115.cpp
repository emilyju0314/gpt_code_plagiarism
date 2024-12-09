#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        long long h;
        cin >> n >> h;

        vector<int> attacks(n);
        
        for (int j = 0; j < n; j++) {
            cin >> attacks[j];
        }

        int lo = 1;
        int hi = 1e9;

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            vector<long long> prefix_sum(mid + 1);

            for (int j = 0; j < n; j++) {
                int cnt = 0;
                cnt += attacks[j] / mid;
                if (attacks[j] % mid != 0) cnt++;

                prefix_sum[attacks[j] % mid] += 1;
                prefix_sum[cnt] -= 1;
            }

            long long sum = 0;
            for (int j = 1; j <= mid; j++) {
                prefix_sum[j] += prefix_sum[j - 1];
                sum += prefix_sum[j];
            }

            if (sum >= h) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        cout << lo << endl;
    }

    return 0;
}