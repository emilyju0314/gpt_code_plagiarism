#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> alpinists;
    for (int i = 0; i < n; ++i) {
        int s, a;
        cin >> s >> a;
        alpinists.push_back({s, a});
    }

    sort(alpinists.begin(), alpinists.end());

    vector<int> dp(n, 0);
    int maxAlpinists = 0;

    for (int i = 0; i < n; ++i) {
        int s = alpinists[i].first;
        int a = alpinists[i].second;

        if (d <= a) {
            dp[i] = 1;
            if (i > 0) dp[i] = max(dp[i], dp[i-1] + 1);
        }

        if (i > 0) dp[i] = max(dp[i], dp[i-1]);

        maxAlpinists = max(maxAlpinists, dp[i]);
    }

    cout << maxAlpinists << endl;

    return 0;
}