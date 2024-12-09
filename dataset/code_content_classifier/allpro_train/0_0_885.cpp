#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, x, m;
        cin >> n >> x >> m;

        int left = x, right = x;
        vector<pair<int, int>> intervals;

        for(int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;

            if(l <= right && r >= left) {
                left = min(left, l);
                right = max(right, r);
            } else {
                intervals.push_back({l, r});
            }
        }

        for(auto interval : intervals) {
            if(interval.first <= right && interval.second >= left) {
                left = min(left, interval.first);
                right = max(right, interval.second);
            }
        }

        cout << (right - left + 1) << endl;
    }

    return 0;
}