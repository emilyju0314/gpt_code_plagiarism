#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> alpinists(n);
    for(int i = 0; i < n; i++) {
        cin >> alpinists[i].first >> alpinists[i].second;
    }

    sort(alpinists.begin(), alpinists.end(), cmp);

    int maxAlpinists = 0;
    vector<int> dp(n, 0);

    for(int i = 0; i < n; i++) {
        if(alpinists[i].first >= d) {
            dp[i] = 1;
        }

        if(i > 0) {
            dp[i] = max(dp[i], dp[i-1]);
        }

        if(alpinists[i].second >= d) {
            int idx = lower_bound(alpinists.begin(), alpinists.begin() + i, make_pair(d, -1), cmp) - alpinists.begin();
            if(idx > 0) {
                dp[i] = max(dp[i], dp[idx-1] + 1);
            } else {
                dp[i] = max(dp[i], dp[0] + 1);
            }
        }

        maxAlpinists = max(maxAlpinists, dp[i]);
    }

    cout << maxAlpinists << endl;

    return 0;
}