#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> robots(k);
    for(int i = 0; i < k; i++) {
        cin >> robots[i].first >> robots[i].second;
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    queue<pair<int, int>> q;
    for(auto robot : robots) {
        q.push(robot);
        dist[robot.first][robot.second] = 0;
    }

    int maxTravelTime = 0;
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();

        for(auto dir : directions) {
            int nextX = curr.first + dir.first;
            int nextY = curr.second + dir.second;

            if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && dist[nextX][nextY] == -1) {
                dist[nextX][nextY] = dist[curr.first][curr.second] + 1;
                maxTravelTime = max(maxTravelTime, dist[nextX][nextY]);
                q.push({nextX, nextY});
            }
        }
    }

    cout << maxTravelTime << endl;

    return 0;
}