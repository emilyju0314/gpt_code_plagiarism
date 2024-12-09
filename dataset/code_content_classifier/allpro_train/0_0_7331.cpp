#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> intervals(k);
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        intervals[i] = make_pair(l, r);
    }

    sort(intervals.begin(), intervals.end());

    int total_flips = 0;
    int start_time = 0;
    int end_time = 2*n;

    for (int i = 0; i < k; i++) {
        if (intervals[i].first <= start_time) {
            start_time = max(start_time, intervals[i].second);
        } else {
            total_flips++;
            start_time = max(start_time, intervals[i].second);
        }
    }

    if (start_time < end_time) {
        cout << "Hungry" << endl;
    } else {
        cout << "Full" << endl;
        cout << total_flips << endl;
    }

    return 0;
}