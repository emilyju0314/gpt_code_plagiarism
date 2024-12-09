#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct Mine {
    int x, y, timer;
};

bool operator<(const Mine& m1, const Mine& m2) {
    return m1.timer > m2.timer;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<Mine> mines(n);

        for (int j = 0; j < n; j++) {
            cin >> mines[j].x >> mines[j].y >> mines[j].timer;
        }

        sort(mines.begin(), mines.end());

        map<pair<int, int>, int> detonated;

        for (const Mine& mine : mines) {
            int x = mine.x, y = mine.y;
            for (int dx = -k; dx <= k; dx++) {
                for (int dy = -k; dy <= k; dy++) {
                    if (abs(dx) + abs(dy) > k) continue;
                    pair<int, int> pos = {x + dx, y + dy};
                    if (detonated.count(pos)) continue;
                    detonated[pos] = 1;
                }
            }
        }

        int max_timer = 0;
        for (const Mine& mine : mines) {
            if (!detonated.count({mine.x, mine.y})) {
                max_timer = max(max_timer, mine.timer);
            }
        }

        cout << max_timer << endl;
    }

    return 0;
}