#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (v[i] > v[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
