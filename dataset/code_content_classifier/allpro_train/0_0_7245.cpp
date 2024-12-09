#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Junction {
    int maxDistance;
    int cost;
};

struct Road {
    int destination;
    int length;
};

struct Node {
    int junction;
    int distance;
    int cost;

    bool operator<(const Node& other) const {
        return cost > other.cost;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    int x, y;
    cin >> x >> y;

    vector<vector<Road>> roads(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        roads[u].push_back({v, w});
        roads[v].push_back({u, w});
    }

    vector<Junction> junctions(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> junctions[i].maxDistance >> junctions[i].cost;
    }

    vector<int> minCost(n+1, numeric_limits<int>::max());
    priority_queue<Node> pq;
    pq.push({x, 0, 0});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.junction == y) {
            cout << current.cost << endl;
            return 0;
        }

        for (Road road : roads[current.junction]) {
            if (current.distance + road.length <= junctions[road.destination].maxDistance) {
                int newCost = current.cost + junctions[road.destination].cost;
                if (newCost < minCost[road.destination]) {
                    minCost[road.destination] = newCost;
                    pq.push({road.destination, current.distance + road.length, newCost});
                }
            }
        }
    }

    cout << "-1" << endl;

    return 0;
}