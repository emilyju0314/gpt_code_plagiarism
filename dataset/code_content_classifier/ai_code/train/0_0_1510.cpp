#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<double> dp(n + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            dp[j] = max(dp[j], dp[i] + (j - i - 1) - (p[j - 1] - 1) + (p[i] - 1));
        }
    }

    double result = n - dp[n];
    cout << fixed;
    cout.precision(6);
    cout << result << endl;

    return 0;
}