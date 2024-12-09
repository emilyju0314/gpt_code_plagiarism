#include <iostream>
#include <vector>

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
            if (a[i] > a[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
        }

        int max_k = 1;
        for (int i = 0; i < n; i++) {
            max_k = max(max_k, dp[i]);
        }

        cout << max_k << endl;
    }

    return 0;
}