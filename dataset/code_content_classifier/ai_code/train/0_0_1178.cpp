#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> positions(n);
    map<pair<int, int>, int> count_xy, count_x, count_y;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        positions[i] = {x, y};
        count_xy[{x, y}]++;
        count_x[x]++;
        count_y[y]++;
    }

    long long ans = 0;

    for (auto &[xy, cnt] : count_xy) {
        ans += 1LL * cnt * (cnt - 1) / 2;
    }

    for (int i = 0; i < n; i++) {
        int x = positions[i].first;
        int y = positions[i].second;

        ans -= 1LL * (count_x[x] - 1) * (count_y[y] - 1);
    }

    cout << ans << endl;

    return 0;
}