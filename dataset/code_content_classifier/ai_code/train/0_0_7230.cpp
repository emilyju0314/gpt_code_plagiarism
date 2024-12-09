#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> verticals, horizontals;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2) {
            for (int j = min(y1, y2); j <= max(y1, y2); j++) {
                verticals.insert(x1 * 200000 + j);
            }
        } else {
            for (int j = min(x1, x2); j <= max(x1, x2); j++) {
                horizontals.insert(y1 * 200000 + j);
            }
        }
    }

    cout << verticals.size() + horizontals.size() << endl;

    return 0;
}