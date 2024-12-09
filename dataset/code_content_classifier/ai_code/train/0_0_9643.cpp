#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> calls(n);
    for (int i = 0; i < n; i++) {
        cin >> calls[i].first >> calls[i].second;
    }

    int max_sleep = 0;
    for (int i = 0; i < n; i++) {
        vector<int> sleep_intervals;
        for (int j = max(i - k, 0); j < n; j++) {
            int sleep_start = (j == 0) ? 1 : calls[j - 1].first + calls[j - 1].second;
            int sleep_end = (j == n - 1) ? 86400 : calls[j].first;
            sleep_intervals.push_back(sleep_end - sleep_start);
        }

        int total_sleep = 0;
        for (int interval : sleep_intervals) {
            total_sleep += interval;
        }

        max_sleep = max(max_sleep, total_sleep);
    }

    cout << max_sleep << endl;

    return 0;
}