#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> bannedCells;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        bannedCells.insert(make_pair(x, y));
    }

    int maxPoints = 0;
    for (int i = 2; i < n; i++) {
        if (!bannedCells.count(make_pair(1, i))) {
            maxPoints++;
            bannedCells.insert(make_pair(n, i));
        }
        if (!bannedCells.count(make_pair(n, i))) {
            maxPoints++;
            bannedCells.insert(make_pair(1, i));
        }
        if (!bannedCells.count(make_pair(i, 1))) {
            maxPoints++;
            bannedCells.insert(make_pair(i, n));
        }
        if (!bannedCells.count(make_pair(i, n))) {
            maxPoints++;
            bannedCells.insert(make_pair(i, 1));
        }
    }

    cout << maxPoints << endl;

    return 0;
}