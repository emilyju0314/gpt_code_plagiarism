#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Range {
    int l, r;
};

vector<pair<int, pair<int, int>>> playGame(vector<Range>& ranges, int n) {
    map<int, Range> rangeMap;
    for (int i = 1; i <= n; i++) {
        rangeMap[i] = {i, i};
    }

    for (const auto& range : ranges) {
        for (int i = range.l; i <= range.r; i++) {
            int d = i;
            rangeMap.erase(d);
            if (range.l < d) rangeMap[range.l] = {range.l, d - 1};
            if (d < range.r) rangeMap[d] = {d + 1, range.r};
        }
    }

    vector<pair<int, pair<int, int>> res;
    for (const auto& it : rangeMap) {
        res.push_back({it.second.l, {it.second.r, it.first}});
    }

    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<Range> ranges(n);
        
        for (int i = 0; i < n; i++) {
            cin >> ranges[i].l >> ranges[i].r;
        }

        vector<pair<int, pair<int, int>> result = playGame(ranges, n);

        // Output result
        for (const auto& p : result) {
            cout << p.first << " " << p.second.first << " " << p.second.second << endl;
        }
    }

    return 0;
}