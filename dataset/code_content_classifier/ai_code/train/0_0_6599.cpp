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

        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int max_len = *max_element(dp.begin(), dp.end());

        int min_exchanges = n - max_len;
        cout << min_exchanges << endl;
    }

    return 0;
}