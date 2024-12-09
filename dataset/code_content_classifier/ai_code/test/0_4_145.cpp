#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Mine {
    int x, y, timer;
};

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<Mine> mines(n);
        for(int i = 0; i < n; i++) {
            cin >> mines[i].x >> mines[i].y >> mines[i].timer;
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({-mines[i].timer, {mines[i].x, mines[i].y}});
        }

        int max_time = 0;
        vector<vector<bool>> visited(2 * 10^9 + 1, vector<bool>(2 * 10^9 + 1, false));

        while(!pq.empty()) {
            int timer = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(visited[x][y]) continue;
            visited[x][y] = true;

            max_time = max(max_time, timer);

            for(int i = -k; i <= k; i++) {
                if(i == 0) continue;
                if(x + i >= -10^9 && x + i <= 10^9) pq.push({-(timer+1), {x + i, y}});
                if(y + i >= -10^9 && y + i <= 10^9) pq.push({-(timer+1), {x, y + i}});
            }
        }

        cout << max_time << endl;
    }

    return 0;
}