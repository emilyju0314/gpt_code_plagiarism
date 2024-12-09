#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

int n;
vector<long long> a;
vector<vector<int>> adj;

int bfs(int start) {
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            } else if (dist[neighbor] > 0 && dist[node] > 1) {
                return dist[neighbor] + dist[node] + 1;
            }
        }
    }

    return -1;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    adj.resize(n);
    unordered_set<long long> uniqueValues(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[i] & a[j]) != 0) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int shortestCycleLength = -1;
    for (int i = 0; i < n; i++) {
        int cycleLength = bfs(i);
        if (cycleLength != -1 && (shortestCycleLength == -1 || cycleLength < shortestCycleLength)) {
            shortestCycleLength = cycleLength;
        }
    }

    cout << shortestCycleLength << endl;

    return 0;
}