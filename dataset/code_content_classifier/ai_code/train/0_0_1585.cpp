#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int l;
    cin >> l;

    vector<int> points(l);
    for (int i = 0; i < l; ++i) {
        cin >> points[i];
    }

    string s;
    cin >> s;

    vector<int> dp(l+1, 0);
    for (int i = 1; i <= l; ++i) {
        dp[i] = dp[i-1]; // Initialize with previous value
        for (int j = 1; j <= i; ++j) {
            string sub = s.substr(j-1, i-j+1);
            if (sub == string(sub.rbegin(), sub.rend())) {
                dp[i] = max(dp[i], dp[j-1] + points[i-1]);
            }
        }
    }

    cout << dp[l] << endl;

    return 0;
}