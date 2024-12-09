#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<pair<int, int>> ranges(n);
        for (int j = 0; j < n; j++) {
            int l, r;
            cin >> l >> r;
            ranges[j] = make_pair(l, r);
        }

        for (const auto& range : ranges) {
            int l = range.first;
            int r = range.second;
            int d = l;
            cout << l << " " << r << " " << d << endl;
        }
    }

    return 0;
}