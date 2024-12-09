#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct Ice {
    int x, y;
    int dist;
};

bool operator<(const Ice& a, const Ice& b) {
    return a.dist > b.dist;
}

int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    int sx, sy, tx, ty, n;
    cin >> sx >> sy >> tx >> ty >> n;

    vector<Ice> ice_blocks(n);
    for (int i = 0; i < n; i++) {
        cin >> ice_blocks[i].x >> ice_blocks[i].y;
    }

    // Calculate the initial distance from start to destination
    int init_dist = manhattan_distance(sx, sy, tx, ty);

    // Calculate the minimum distance to reach from start to holes through the ice blocks
    priority_queue<Ice> pq;
    pq.push({sx, sy, init_dist});

    while (!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int dist = pq.top().dist;
        pq.pop();

        // If we reach any of the holes
        if (x == tx && y == ty) {
            cout << init_dist - dist << endl;
            return 0;
        }

        for (int i = 0; i < n; i++) {
            int new_dist = dist - manhattan_distance(x, y, tx, ty) + manhattan_distance(ice_blocks[i].x, ice_blocks[i].y, tx, ty) + 1;
            pq.push({ice_blocks[i].x, ice_blocks[i].y, new_dist});
        }
    }

    cout << -1 << endl;
    return 0;
}