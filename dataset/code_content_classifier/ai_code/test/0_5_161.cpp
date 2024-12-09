#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, pair<int, int>>> ranges;
        
        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            ranges.push_back({r - l + 1, {l, r}});
        }

        sort(ranges.begin(), ranges.end());

        int currNum = 1;
        for (int i = 0; i < n; ++i) {
            int l = ranges[i].second.first;
            int r = ranges[i].second.second;
            for (int j = 0; j <= r - l; ++j) {
                cout << l << " " << r << " " << currNum << endl;
                ++currNum;
            }
        }
    }

    return 0;
}