#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> diff;
    long long total = 0;

    for (int i = 0; i < n; i++) {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;

        if (a1 >= b1) {
            diff.push_back({a1, b1});
            total += a1;
        } else if (a2 >= b2) {
            diff.push_back({a2, b2});
            total += a2;
        } else if (b1 - a2 >= 0) {
            total += a2;
            diff.push_back({a1, b1});
            diff.push_back({a2, b2});
        } else {
            total += a1;
            diff.push_back({a1, b1});
            diff.push_back({a2, b2});
        }
    }

    sort(diff.begin(), diff.end(), greater<pair<int, int>>());

    int ans = 0;
    for (int i = 0; i < diff.size(); i++) {
        if (i % 2 == 0) {
            ans += diff[i].first;
        } else {
            ans -= diff[i].second;
        }
    }

    cout << ans - total << endl;

    return 0;
}