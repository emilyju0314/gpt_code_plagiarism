#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> distances;

bool canCompleteMission(int k) {
    queue<int> q;
    vector<bool> visited(n + 1, false);

    q.push(1);
    visited[1] = true;
    distances[1] = 0;

    int maxDistance = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distances[neighbor] = distances[curr] + 1;
                maxDistance = max(maxDistance, distances[neighbor]);

                if (distances[neighbor] <= k) {
                    q.push(neighbor);
                }
            }
        }
    }

    return (maxDistance <= 2 * k);
}

int findMinK() {
    int low = 1, high = n, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canCompleteMission(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        graph.assign(n + 1, vector<int>());
        distances.assign(n + 1, 0);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int minK = findMinK();
        cout << minK << endl;
    }

    return 0;
}