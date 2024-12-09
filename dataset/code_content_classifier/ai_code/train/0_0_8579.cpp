#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans, d;

    // Find the smallest element
    int l = 0, r = 1e9;
    while (l < r) {
        int m = (l + r) / 2;
        cout << "> " << m << endl;
        int response;
        cin >> response;
        if (response == 1) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    ans = l;

    // Find the common difference
    vector<int> diffs;
    for (int i = 1; i < n; i++) {
        cout << "? " << i << endl;
        int ai;
        cin >> ai;
        diffs.push_back(ai - ans);
    }

    sort(diffs.begin(), diffs.end());
    d = diffs[0];

    cout << "! " << ans << " " << d << endl;

    return 0;
}