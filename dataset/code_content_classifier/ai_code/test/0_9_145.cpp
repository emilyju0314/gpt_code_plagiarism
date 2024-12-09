#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Mine {
    int x, y, timer;

    Mine(int x, int y, int timer) : x(x), y(y), timer(timer) {}

    bool operator<(const Mine& other) const {
        return timer > other.timer;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        priority_queue<Mine> pq;

        int maxX = INT_MIN, maxY = INT_MIN;
        for (int i = 0; i < n; i++) {
            int x, y, timer;
            cin >> x >> y >> timer;

            maxX = max(maxX, abs(x));
            maxY = max(maxY, abs(y));

            pq.push(Mine(x, y, timer));
        }

        int maxTime = 0;
        while (!pq.empty()) {
            Mine curr = pq.top();
            pq.pop();

            int time = max(max(abs(curr.x), abs(curr.y)), max(maxX - abs(curr.x), maxY - abs(curr.y)));
            maxTime = max(maxTime, time + curr.timer);

            if (!pq.empty()) {
                Mine next = pq.top();
                pq.pop();
                pq.push(Mine(next.x, next.y, max(time + 1, next.timer))); // update the timer of the next mine
            }
        }

        cout << maxTime << endl;
    }

    return 0;
}