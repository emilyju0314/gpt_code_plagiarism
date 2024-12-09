#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> nails(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        nails[i] = make_pair(x, y);
    }

    vector<int> rods(m);
    for (int i = 0; i < m; i++) {
        cin >> rods[i];
    }

    vector<int> fold_place(n, -1);

    for (int i = 1; i < n; i += 2) {
        int dx = abs(nails[i].first - nails[i-1].first);
        int dy = abs(nails[i].second - nails[i-1].second);
        int rod_index = find(rods.begin(), rods.end(), max(dx, dy)) - rods.begin();
        rods[rod_index] = -1;
        fold_place[i] = rod_index + 1;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << fold_place[i] << " ";
    }

    return 0;
}