#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool isBetween(int a, int b, int c) {
    return a <= b && b <= c;
}

bool canHit(const Point& start, const Point& target, const Point& monster) {
    if (start.x == target.x && start.x == monster.x) return true;
    if (start.y == target.y && start.y == monster.y) return true;
    if ((start.x - monster.x) * (target.y - monster.y) == (start.y - monster.y) * (target.x - monster.x)) {
        if (isBetween(start.x, monster.x, target.x) && isBetween(start.y, monster.y, target.y)) {
            return true;
        }
    }
    return false;
}

int main() {
    int k, n;
    cin >> k >> n;

    vector<Point> stones(k);
    vector<Point> monsters(n);

    for (int i = 0; i < k; i++) {
        cin >> stones[i].x >> stones[i].y;
    }

    for (int i = 0; i < n; i++) {
        cin >> monsters[i].x >> monsters[i].y;
    }

    int afraidCount = 0;

    for (int i = 0; i < n; i++) {
        bool afraid = false;
        for (int j = 0; j < (1 << k); j++) {
            Point current = stones[0];
            for (int l = 0; l < k; l++) {
                if (j & (1 << l)) {
                    if (canHit(current, stones[l], monsters[i])) {
                        afraid = true;
                        break;
                    }
                    current = stones[l];
                }
            }
            if (afraid) break;
            if (canHit(current, monsters[i], monsters[i])) {
                afraid = true;
                break;
            }
        }
        if (afraid) afraidCount++;
    }

    cout << afraidCount << endl;

    return 0;
}