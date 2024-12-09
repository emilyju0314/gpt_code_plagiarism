#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Road {
    int from, to;
};

struct Suit {
    int t, c, v, u;
};

struct SuitPosition {
    int suitIdx;
    double time;
    int location;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Road> roads(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> roads[i].from >> roads[i].to;
    }

    vector<Suit> suits(m);
    priority_queue<SuitPosition, vector<SuitPosition>, [](SuitPosition a, SuitPosition b) -> bool {
        return a.time > b.time;
    }> pq;

    for (int i = 0; i < m; i++) {
        cin >> suits[i].t >> suits[i].c >> suits[i].v >> suits[i].u;
        pq.push({i, suits[i].t, suits[i].v});
    }

    double explosionTime = -1;
    vector<int> suitLocations(n, -1);

    while (!pq.empty()) {
        SuitPosition sp = pq.top();
        pq.pop();

        if (suitLocations[sp.location] != -1) {
            double elapsedTime = abs(suits[sp.suitIdx].t - suitLocations[sp.location]) / static_cast<double>(suits[sp.suitIdx].c);
            explosionTime = sp.time + elapsedTime;
            break;
        }

        suitLocations[sp.location] = sp.time;

        // Move the suit to the next position if needed
        for (Road road : roads) {
            if (road.from == sp.location) {
                double distance = 1; // Assuming distance between junctions is 1
                double travelTime = distance / static_cast<double>(suits[sp.suitIdx].c);
                pq.push({sp.suitIdx, sp.time + travelTime, road.to});
            } else if (road.to == sp.location) {
                double distance = 1; // Assuming distance between junctions is 1
                double travelTime = distance / static_cast<double>(suits[sp.suitIdx].c);
                pq.push({sp.suitIdx, sp.time + travelTime, road.from});
            }
        }
    }

    cout << explosionTime << endl;

    return 0;
}