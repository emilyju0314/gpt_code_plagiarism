#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> graph; // Adjacency list to store the graph
vector<bool> visited; // Array to mark visited intersections
vector<int> residualDistance; // Array to keep track of remaining distance to reach the initial intersection

bool dfs(int currentIntersection, int initialIntersection, int currentDistance, int resetPoint) {
    visited[currentIntersection] = true;

    // Calculate the remaining distance to reach the initial intersection and update the odometer reading
    int remainingDistance = residualDistance[currentIntersection] - currentDistance;
    if (remainingDistance % resetPoint == 0) {
        return true;
    }

    // Explore all roads from the current intersection
    for (auto road : graph[currentIntersection]) {
        int nextIntersection = road.first;
        int roadLength = road.second;
        if (!visited[nextIntersection]) {
            residualDistance[nextIntersection] = currentDistance + roadLength; // Update the residual distance for the next intersection
            if (dfs(nextIntersection, initialIntersection, currentDistance + roadLength, resetPoint)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    visited.assign(n + 1, false);
    residualDistance.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
    }

    int q;
    cin >> q;

    while (q--) {
        int startIntersection, initialOdometer, resetPoint;
        cin >> startIntersection >> initialOdometer >> resetPoint;

        // Reset the arrays for a new query
        visited.assign(n + 1, false);
        residualDistance[startIntersection] = initialOdometer;

        if (dfs(startIntersection, startIntersection, initialOdometer, resetPoint)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}