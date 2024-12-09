#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    unordered_set<int> blocked;
    for (int i = 0; i < k; i++) {
        int xi, yi;
        cin >> xi >> yi;
        blocked.insert((xi-1)*m + yi);
    }

    int xs, ys, dx, dy;
    cin >> xs >> ys;
    string direction;
    cin >> direction;

    if (direction == "NE") {
        dx = -1;
        dy = 1;
    } else if (direction == "NW") {
        dx = -1;
        dy = -1;
    } else if (direction == "SE") {
        dx = 1;
        dy = 1;
    } else {
        dx = 1;
        dy = -1;
    }

    long long count = 0;
    while (xs >= 1 && xs <= n && ys >= 1 && ys <= m) {
        if (!blocked.count((xs-1)*m + ys)) {
            count++;
        }
        if ((dx == -1 && xs == 1) || (dx == 1 && xs == n)) {
            dx = -dx;
        }
        if ((dy == -1 && ys == 1) || (dy == 1 && ys == m)) {
            dy = -dy;
        }
        xs += dx;
        ys += dy;
    }

    cout << count << endl;

    return 0;
}