#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> ropes(m);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        ropes[i] = make_pair(l, r);
    }

    sort(ropes.begin(), ropes.end());

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        
        int max_height = x;

        for (int j = 0; j < m; j++) {
            if (ropes[j].first <= x && ropes[j].second >= x) {
                max_height = max(max_height, ropes[j].second);
            }
        }

        cout << min(max_height, y) << endl;
    }

    return 0;
}