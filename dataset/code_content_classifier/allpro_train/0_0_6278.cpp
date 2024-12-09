#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1); // Using 1-based indexing
    vector<int> inDegree(n+1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cnt++;

        for (int neighbor : graph[curr]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (cnt != n) {
        cout << -1 << endl;
    } else {
        cout << cnt << endl;
    }

    return 0;
}