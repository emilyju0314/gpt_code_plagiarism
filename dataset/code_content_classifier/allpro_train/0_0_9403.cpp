#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1, false);
    vector<int> distances(n+1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int brain_latency = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int next : adj[curr]) {
                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                        distances[next] = distances[curr] + 1;
                        brain_latency = max(brain_latency, distances[next]);
                    }
                }
            }
        }
    }

    cout << brain_latency << endl;

    return 0;
}