#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Passage {
    int start;
    int end;
    int time_start;
    int time_end;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Passage>> passages(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, l, r;
        cin >> a >> b >> l >> r;
        passages[a].push_back({a, b, l, r});
        passages[b].push_back({b, a, l, r});
    }

    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int curr_time = pq.top().first;
        int curr_place = pq.top().second;
        pq.pop();

        if (curr_place == n) {
            cout << curr_time << endl;
            return 0;
        }

        for (Passage passage : passages[curr_place]) {
            int next_time = max(passage.time_start, curr_time) + 1;
            if (next_time <= passage.time_end && next_time < dist[passage.end]) {
                dist[passage.end] = next_time;
                pq.push({next_time, passage.end});
            }
        }
    }

    cout << -1 << endl;

    return 0;
}