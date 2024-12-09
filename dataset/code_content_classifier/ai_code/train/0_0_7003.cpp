#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Signal {
    int ns;
    int ew;
    int state;
};

struct Point {
    int x;
    int y;
    int time;

    bool operator>(const Point& other) const {
        return time > other.time;
    }
};

vector<vector<int>> dijkstra(vector<vector<Signal>>& signals, vector<vector<int>>& distance, Point source, Point destination) {
    int w = signals.size();
    int h = signals[0].size();
    
    vector<vector<int>> time(w, vector<int>(h, INT_MAX));

    priority_queue<Point, vector<Point>, greater<Point>> pq;
    pq.push(source);
    time[source.x][source.y] = 0;

    while (!pq.empty()) {
        Point current = pq.top();
        pq.pop();

        if (current.x == destination.x && current.y == destination.y) {
            return time;
        }

        if (current.time > time[current.x][current.y]) {
            continue;
        }

        // Possible moves
        vector<Point> moves = {
            {current.x + 1, current.y, current.time + distance[current.x][current.y]},
            {current.x - 1, current.y, current.time + distance[current.x - 1][current.y]},
            {current.x, current.y + 1, current.time + distance[current.x][current.y]},
            {current.x, current.y - 1, current.time + distance[current.x][current.y - 1]}
        };

        // Check neighboring points
        for (auto move : moves) {
            if (move.x >= 0 && move.x < w && move.y >= 0 && move.y < h && move.time < time[move.x][move.y]) {
                int signal_ns = signals[current.x][current.y].ns;
                int signal_ew = signals[current.x][current.y].ew;
                
                if (signals[current.x][current.y].state == 0) {
                    signal_ew = 100 - signal_ns;
                } else {
                    signal_ns = 100 - signal_ew;
                }

                if (current.time % (signal_ns + signal_ew) < signal_ns) {
                    move.time += signal_ns - (current.time % (signal_ns + signal_ew));
                } else {
                    move.time += signal_ew - (current.time % (signal_ns + signal_ew));
                }

                if (move.time < time[move.x][move.y]) {
                    time[move.x][move.y] = move.time;
                    pq.push(move);
                }
            }
        }
    }

    return time;
}

int main() {
    int w, h;
    while (cin >> w >> h && w != 0 && h != 0) {
        vector<vector<int>> distance(w, vector<int>(h));

        // Read distances between avenues and drives
        for (int i = 0; i < w - 1; i++) {
            cin >> distance[i][0];
        }
        for (int i = 0; i < h - 1; i++) {
            cin >> distance[0][i];
        }

        // Read configuration of traffic signals
        vector<vector<Signal>> signals(w, vector<Signal>(h));
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                cin >> signals[i][j].ns >> signals[i][j].ew >> signals[i][j].state;
            }
        }

        // Read initial and final positions
        Point source, destination;
        cin >> source.x >> source.y >> destination.x >> destination.y;

        // Calculate shortest path
        vector<vector<int>> time = dijkstra(signals, distance, source, destination);

        // Output shortest time to reach destination
        cout << time[destination.x][destination.y] << endl;
    }

    return 0;
}