#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> beacons(n);
    for (int i = 0; i < n; i++) {
        cin >> beacons[i].first >> beacons[i].second;
    }

    sort(beacons.begin(), beacons.end());

    int ans = 0;
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = i - 1;
        while (right >= 0 && beacons[right].first >= beacons[i].first - beacons[i].second) {
            left = max(left, dp[right]);
            right--;
        }
        dp[i] = left + 1;
        ans = max(ans, dp[i]);
    }

    cout << n - ans << endl;

    return 0;
}