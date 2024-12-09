#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> segments;
        int min_r = INT_MAX, max_l = 0;

        for(int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            segments.push_back(make_pair(l, r));

            min_r = min(min_r, r);
            max_l = max(max_l, l);
        }

        int min_length = 0;

        for(int i = 0; i < n; i++) {
            int a = max(max_l, segments[i].first);
            int b = min(min_r, segments[i].second);
            min_length = max(min_length, max(0, b - a));
        }

        cout << min_length << endl;
    }

    return 0;
}