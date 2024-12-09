#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<pair<int, int>> ranges;
        for (int j = 0; j < n; j++) {
            int l, r;
            cin >> l >> r;
            ranges.push_back(make_pair(l, r));
        }

        sort(ranges.begin(), ranges.end());

        int current = 1;
        for (auto range : ranges) {
            int l = range.first;
            int r = range.second;
            cout << l << " " << r << " " << current << endl;
            current++;
        }
    }

    return 0;
}