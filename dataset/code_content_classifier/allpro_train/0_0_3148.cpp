#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<bool> affected(n, false);
    for (int i = 0; i < m; i++) {
        int settlement;
        cin >> settlement;
        affected[settlement - 1] = true;
    }

    vector<vector<int>> adjList(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
        adjList[b - 1].push_back(a - 1);
    }

    vector<int> dist(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : adjList[curr]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }

    int possibleLocations = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] <= d && (d - dist[i]) % 2 == 0) {
            if (!affected[i]) {
                possibleLocations++;
            }
        }
    }

    cout << possibleLocations << endl;

    return 0;
}