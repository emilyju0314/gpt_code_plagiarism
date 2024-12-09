#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Mine {
    int x, y, timer;
};

int findMinTimeToDetonateAllMines(int n, int k, vector<Mine>& mines) {
    // Sort the mines based on their explosion time
    sort(mines.begin(), mines.end(), [](const Mine& a, const Mine& b) {
        return a.timer < b.timer;
    });

    int time = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        int x = mines[i].x, y = mines[i].y, timer = mines[i].timer;
        pq.push({timer, {x, y}});
    }

    while (!pq.empty()) {
        int curr_time = pq.top().first;
        int curr_x = pq.top().second.first;
        int curr_y = pq.top().second.second;
        pq.pop();

        if (curr_time > time) {
            time = curr_time;
        }

        // Detonate all mines within the explosion radius
        while (!pq.empty() && pq.top().first == curr_time) {
            int next_x = pq.top().second.first;
            int next_y = pq.top().second.second;
            if (abs(curr_x - next_x) <= k || abs(curr_y - next_y) <= k) {
                pq.pop();
            } else {
                break;
            }
        }
    }

    return time;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<Mine> mines(n);
        for (int j = 0; j < n; j++) {
            int x, y, timer;
            cin >> x >> y >> timer;
            mines[j] = {x, y, timer};
        }

        int min_time = findMinTimeToDetonateAllMines(n, k, mines);
        cout << min_time << endl;
    }

    return 0;
}