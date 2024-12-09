#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> safety_islands(m);
    for(int i = 0; i < m; i++) {
        cin >> safety_islands[i];
    }
    sort(safety_islands.begin(), safety_islands.end());

    int g, r;
    cin >> g >> r;

    vector<vector<int>> dist(m, vector<int>(g+1, INF));
    queue<pair<int, int>> q;
    q.push({0, 0});

    dist[0][0] = 0;
    while(!q.empty()) {
        int island = q.front().first;
        int time = q.front().second;
        q.pop();

        if(island == m-1) {
            cout << time << endl;
            return 0;
        }

        // Move forward
        if(island < m-1) {
            int next_dist = safety_islands[island+1] - safety_islands[island];
            int next_time = time + next_dist;
            if(next_time < dist[island+1][next_time % g]) {
                dist[island+1][next_time % g] = next_time;
                q.push({island+1, next_time});
            }
        }

        // Move backward
        if(island > 0) {
            int next_dist = safety_islands[island] - safety_islands[island-1];
            if(time >= next_dist) {
                int next_time = time - next_dist;
                if(next_time < dist[island-1][next_time % g]) {
                    dist[island-1][next_time % g] = next_time;
                    q.push({island-1, next_time});
                }
            }
        }

        // Wait for the green light
        int wait_time = g - time % g;
        if(wait_time == 0) wait_time = g;
        int next_time = time + wait_time;
        if(next_time < dist[island][next_time % g]) {
            dist[island][next_time % g] = next_time;
            q.push({island, next_time});
        }
    }

    cout << -1 << endl;

    return 0;
}