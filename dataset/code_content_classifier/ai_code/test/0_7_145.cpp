#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Mine {
    int x, y, timer;
};

struct Compare {
    bool operator()(const Mine& m1, const Mine& m2) {
        return m1.timer > m2.timer; // priority queue in ascending order of explosion time
    }
};

int k;
vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int detonateAllMines(vector<Mine>& mines) {
    priority_queue<Mine, vector<Mine>, Compare> pq;
    for (const Mine& mine : mines) {
        pq.push(mine);
    }
    
    int time = 0;
    while (!pq.empty()) {
        Mine current = pq.top();
        pq.pop();
        
        for (const vector<int>& dir : dirs) {
            int nx = current.x + dir[0];
            int ny = current.y + dir[1];
            for (int i = 0; i < mines.size(); i++) {
                if (abs(mines[i].x - nx) <= k && abs(mines[i].y - ny) <= k) {
                    pq.push(mines[i]);
                    mines.erase(mines.begin() + i);
                }
            }
        }
        
        time = max(time, current.timer);
    }
    
    return time;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n >> k;
        
        vector<Mine> mines;
        for (int j = 0; j < n; j++) {
            int x, y, timer;
            cin >> x >> y >> timer;
            mines.push_back({x, y, timer});
        }
        
        sort(mines.begin(), mines.end(), [](Mine& m1, Mine& m2) { return m1.timer < m2.timer; });
        int minTime = detonateAllMines(mines);
        cout << minTime << endl;
    }
    
    return 0;
}