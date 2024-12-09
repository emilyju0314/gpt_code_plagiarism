#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> dp(n, 1);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(min(a[i], a[j]) >= min(a[j], a[dp[j]]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        int maxLen = *max_element(dp.begin(), dp.end());
        cout << maxLen << endl;
    }

    return 0;
}