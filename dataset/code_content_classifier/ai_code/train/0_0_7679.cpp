#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> path(n);
    unordered_map<int, pair<int, int>> coords;

    for (int i = 0; i < n; i++) {
        cin >> path[i];
    }

    for (int i = 0; i < n; i++) {
        coords[path[i]] = {i + 1, i + 1};
    }

    int x = 1, y = 1;
    bool possible = true;

    for (int i = 1; i < n; i++) {
        int dx = abs(coords[path[i]].first - coords[path[i-1]].first);
        int dy = abs(coords[path[i]].second - coords[path[i-1]].second);

        if (dx > 1 || dy > 1 || (dx == 0 && dy == 0)) {
            possible = false;
            break;
        }

        x = max(x, dx);
        y = max(y, dy);
    }

    if (possible) {
        cout << "YES" << endl;
        cout << x << " " << y << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}