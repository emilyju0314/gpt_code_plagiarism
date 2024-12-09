#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    string t, p;
    cin >> t >> p;
    int n = t.size();

    unordered_map<char, vector<int>> idx;
    for (int i = 0; i < n; i++) {
        idx[t[i]].push_back(i);
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    int l = -1, r = n;
    for (char c : p) {
        if (idx.find(c) == idx.end()) {
            cout << 0 << endl;
            return 0;
        }
        int pos = idx[c][0];
        if (pos < l || pos >= r) {
            cout << 0 << endl;
            return 0;
        }
        l = pos;
        auto it = upper_bound(idx[c].begin(), idx[c].end(), l);
        if (it == idx[c].end() || *it >= r) {
            cout << 0 << endl;
            return 0;
        }
        r = *it;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= l && a[i] < r) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}