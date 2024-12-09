#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    priority_queue<int> pq;
    long long ans = 0;

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            vector<int> values;
            for (int i = l; i <= r; i++) {
                values.push_back(intervals[i].second - intervals[i].first);
            }
            sort(values.begin(), values.end());
            int sum = 0;
            for (int i = 0; i < k; i++) {
                sum += values[values.size() - 1 - i];
            }
            pq.push(sum);
            ans = max(ans, (long long)pq.top() * (r - l + 1));
        }
    }

    cout << ans << endl;

    return 0;
}