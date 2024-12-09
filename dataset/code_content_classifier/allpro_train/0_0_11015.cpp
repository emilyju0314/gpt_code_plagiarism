#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaximumNumberOfModels(int n, vector<int>& sizes) {
    vector<int> dp(n, 1);
    int ans = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            if (sizes[i] % sizes[j] == 0 && sizes[j] < sizes[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> sizes(n);

        for (int j = 0; j < n; j++) {
            cin >> sizes[j];
        }

        int result = getMaximumNumberOfModels(n, sizes);
        cout << result << endl;
    }

    return 0;
}