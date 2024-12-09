#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

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

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int left = a[i], right = a[i];

            int j = i - 1;
            while (j >= 0 && a[j] < left) {
                left = a[j];
                j--;
            }

            j = i + 1;
            while (j < n && a[j] < right) {
                right = a[j];
                j++;
            }

            long long segments = j - i;
            long long sum = ((i + 1) * (n - j) % MOD) % MOD;
            long long val = (left + right) % MOD;

            ans = (ans + (val * segments % MOD * sum % MOD) % MOD) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}