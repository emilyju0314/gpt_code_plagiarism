#include <iostream>
#include <vector>

using namespace std;

long long getMaximalValue(vector<int>& values, vector<int>& colors, int a, int b) {
    int n = values.size();
    vector<long long> dp(n);
    long long maxVal = 0;

    for (int i = 0; i < n; ++i) {
        dp[i] = values[i] * b;

        if (i > 0 && colors[i] == colors[i-1]) {
            dp[i] = max(dp[i], dp[i-1] + (long long)values[i] * a);
        }

        maxVal = max(maxVal, dp[i]);
    }

    return maxVal;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> values(n), colors(n);

    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        long long result = getMaximalValue(values, colors, a, b);
        cout << result << endl;
    }

    return 0;
}