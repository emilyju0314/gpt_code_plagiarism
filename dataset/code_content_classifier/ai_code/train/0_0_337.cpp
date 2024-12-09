#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    vector<pair<int, int>> intervals;
    for(int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        intervals.push_back(make_pair(l, r));
    }

    sort(intervals.begin(), intervals.end());

    int x = 0, y = 0;
    int maxRight = 0;
    for(int i = 0; i < N; i++) {
        if(intervals[i].first > maxRight) {
            x += intervals[i].first - maxRight;
            maxRight = intervals[i].first;
        }
        maxRight = max(maxRight, intervals[i].second);
    }
    x += L - maxRight;

    int maxRight2 = 0;
    for(int i = 0; i < N; i++) {
        if(intervals[i].first > maxRight2) {
            y++;
            maxRight2 = maxRight;
        }
        maxRight2 = max(maxRight2, intervals[i].second);
    }

    cout << x << " " << y << endl;

    return 0;
}