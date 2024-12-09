#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Mine {
    int x, y, timer;
    Mine(int x, int y, int timer) : x(x), y(y), timer(timer) {}
    bool operator>(const Mine& other) const {
        return timer > other.timer;
    }
};

int detonateMines(int n, int k, vector<Mine>& mines) {
    priority_queue<Mine, vector<Mine>, greater<Mine>> pq;
    
    for (const Mine& mine : mines) {
        pq.push(mine);
    }
    
    int result = 0;
    while (!pq.empty()) {
        Mine current = pq.top();
        pq.pop();
        if (current.timer <= result) continue;
        result = current.timer;
        
        for (int i = -k; i <= k; i++) {
            for (int j = -k; j <= k; j++) {
                if (i == 0 && j == 0) continue;
                for (auto it = pq.begin(); it != pq.end();) {
                    if (abs(it->x - current.x) <= abs(i) && abs(it->y - current.y) <= abs(j)) {
                        it = pq.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
        }
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        
        vector<Mine> mines;
        for (int j = 0; j < n; j++) {
            int x, y, timer;
            cin >> x >> y >> timer;
            Mine mine(x, y, timer);
            mines.push_back(mine);
        }
        
        int result = detonateMines(n, k, mines);
        cout << result << endl;
    }
    
    return 0;
}