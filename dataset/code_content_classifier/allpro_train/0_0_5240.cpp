#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> probabilities(n);
    for(int i = 0; i < n; i++) {
        cin >> probabilities[i];
    }

    sort(probabilities.rbegin(), probabilities.rend());

    vector<double> dp(n+1);
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + 100.0 / probabilities[i-1];
        for(int j = 1; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + 100.0 / probabilities[j-1]);
        }
    }

    cout << fixed << setprecision(10) << dp[n] << endl;

    return 0;
}