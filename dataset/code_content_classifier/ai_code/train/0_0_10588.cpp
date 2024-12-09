#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<pair<int, int>> segments;
        for(int j = 0; j < n; j++) {
            int l, r;
            cin >> l >> r;
            segments.push_back({l, r});
        }

        sort(segments.begin(), segments.end());

        int ans = 0;
        int max_r = segments[0].second;
        for(int j = 1; j < n; j++) {
            if(segments[j].first > max_r) {
                ans++;
                max_r = segments[j].second;
            } else {
                max_r = max(max_r, segments[j].second);
            }
        }

        cout << ans << endl;
    }

    return 0;
}