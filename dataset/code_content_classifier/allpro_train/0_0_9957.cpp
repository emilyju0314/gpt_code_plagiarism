#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

int numOrders;

bool intersect(Point a, Point b, Point c, Point d) {
    return ((a.x - b.x) * (c.y - a.y) + (a.y - b.y) * (a.x - c.x)) * ((a.x - b.x) * (d.y - a.y) + (a.y - b.y) * (a.x - d.x)) < 0 && ((c.x - d.x) * (a.y - c.y) + (c.y - d.y) * (c.x - a.x)) * ((c.x - d.x) * (b.y - c.y) + (c.y - d.y) * (c.x - b.x)) < 0;
}

void backtrack(int pos, int bitmask, vector<Point>& walls, Point ball, vector<bool>& used) {
    if (pos == (int) walls.size() - 1) {
        numOrders++;
        return;
    }

    for (int i = 0; i < (int) walls.size() - 1; i++) {
        if (!used[i] && !intersect(walls[i], walls[i + 1], ball, walls[pos])) {
            used[i] = true;
            backtrack(pos + 1, bitmask | (1 << i), walls, walls[i], used);
            used[i] = false;
        }
    }
}

int main() {
    int N;
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }

        vector<Point> walls(N + 1);
        vector<bool> used(N, false);
        
        Point start;
        cin >> start.x >> start.y;

        for (int i = 0; i < N; i++) {
            cin >> walls[i].x >> walls[i].y;
        }
        walls[N] = walls[0];

        numOrders = 0;
        backtrack(0, 0, walls, start, used);

        cout << numOrders << endl;
    }

    return 0;
}