#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_set<int> bannedCells;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        bannedCells.insert((x-1)*n + y); // convert 2D coordinates to 1D
    }

    int maxPoints = 0;
    for (int i = 2; i < n; i++) {
        if (!bannedCells.count(i) && !bannedCells.count(n*(n-1) + i)) {
            maxPoints++;
        }
    }

    cout << maxPoints << endl;

    return 0;
}