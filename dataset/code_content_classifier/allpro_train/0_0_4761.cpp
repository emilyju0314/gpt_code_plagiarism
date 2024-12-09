#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

#define MOD 1000000007

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N+1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    queue<int> q;
    q.push(1);

    vector<bool> visited(N+1, false);
    visited[1] = true;

    int count = 0;
    bool infinite = false;

    while (!q.empty()) {
        int size = q.size();
        count++;

        while (size--) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                } else {
                    infinite = true;
                    break;
                }
            }
        }

        if (infinite) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Calculate the minimum number of loop iterations required to stop
    cout << count << endl;

    return 0;
}