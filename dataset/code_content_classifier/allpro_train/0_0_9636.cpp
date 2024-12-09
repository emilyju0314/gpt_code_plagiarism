#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

bool checkHappinessIndex(vector<vector<int>>& adjList, vector<int>& occupancy, vector<int>& happinessIndex) {
    int n = adjList.size();
    vector<int> goodMoods(n, 0);
    vector<int> badMoods(n, 0);

    queue<int> q;
    q.push(0);
    vector<bool> visited(n, false);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        visited[curr] = true;

        for (int neighbor : adjList[curr]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                goodMoods[neighbor] = max(0, goodMoods[curr] + occupancy[neighbor]);
                badMoods[neighbor] = max(0, badMoods[curr] + occupancy[neighbor]);
            }
        }
    }

    q.push(0);
    visited.assign(n, false);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        visited[curr] = true;

        for (int neighbor : adjList[curr]) {
            if (!visited[neighbor]) {
                goodMoods[neighbor] = max(goodMoods[neighbor], goodMoods[curr]);
                badMoods[neighbor] = max(badMoods[neighbor], badMoods[curr]);
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (goodMoods[i] - badMoods[i] != happinessIndex[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adjList(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }

        vector<int> occupancy(n);
        for (int i = 0; i < n; i++) {
            cin >> occupancy[i];
        }

        vector<int> happinessIndex(n);
        for (int i = 0; i < n; i++) {
            cin >> happinessIndex[i];
        }

        if (checkHappinessIndex(adjList, occupancy, happinessIndex)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}