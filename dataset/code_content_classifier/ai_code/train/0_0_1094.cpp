#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    map<int, pair<int, int>> diffs;

    for (int i = 1; i < n; i++) {
        int diff = (a[i] - a[0] + m) % m;
        if (diffs.find(diff) == diffs.end()) {
            diffs[diff] = {a[0], diff};
        } else {
            if (diffs[diff].first != a[0]) {
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    for (auto d : diffs) {
        cout << d.second.first << " " << d.second.second << endl;
        return 0;
    }

    cout << "-1" << endl;

    return 0;
}