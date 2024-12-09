#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> hills(n);
    for (int i = 0; i < n; i++) {
        cin >> hills[i];
    }

    vector<int> dp(n, 0);

    for (int i = 1; i < n; i++) {
        dp[i] = dp[i-1];
        for (int j = i-2; j >= 0; j--) {
            if (hills[i] <= hills[j]) {
                dp[i] = dp[i-1] + hills[j] - hills[i] + 1;
                break;
            }
        }
    }

    int q = (n + 1) / 2;
    for (int i = 0; i < q; i++) {
        int houses = i + 1;
        int res = 0;
        for (int j = 0; j < n; j++) {
            if (dp[j] > res) {
                res = dp[j];
            }
        }
        cout << res << " ";
    }
    
    return 0;
}