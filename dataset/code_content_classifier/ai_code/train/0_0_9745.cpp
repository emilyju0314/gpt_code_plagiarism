#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());

    vector<int> dp(n, 1); // dp[i] represents the maximum clique size ending at point i
    int maxClique = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(abs(points[i].first - points[j].first) >= points[i].second + points[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxClique = max(maxClique, dp[i]);
    }

    cout << maxClique << endl;

    return 0;
}