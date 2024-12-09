#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> beauty(n);
    for (int i = 0; i < n; i++) {
        cin >> beauty[i];
    }

    vector<long long> dp(n, 0);
    long long maxBeauty = beauty[0];
    dp[0] = beauty[0];

    for (int i = 1; i < n; i++) {
        dp[i] = beauty[i];
        for (int j = 0; j < i; j++) {
            if (beauty[i] - beauty[j] == i - j) {
                dp[i] = max(dp[i], dp[j] + beauty[i]);
            }
        }
        maxBeauty = max(maxBeauty, dp[i]);
    }

    cout << maxBeauty << endl;

    return 0;
}