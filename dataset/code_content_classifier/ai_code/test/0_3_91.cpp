#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

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
            int left = a[i];
            int right = a[i];
            for (int j = i; j >= 0; j--) {
                left = min(left, a[j]);
                int sum = 0;
                for (int k = i; k >= j; k--) {
                    sum += a[k];
                }
                if (left * (i - j + 1) == sum) {
                    ans = (ans + i - j + 1) % MOD;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}