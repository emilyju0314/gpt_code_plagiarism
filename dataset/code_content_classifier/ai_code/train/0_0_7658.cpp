#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    int total_energy = 0;
    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        total_energy += v[curr-1];

        for (int neighbor : adj[curr]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                pq.push(neighbor);
            }
        }
    }

    cout << total_energy << endl;

    return 0;
}