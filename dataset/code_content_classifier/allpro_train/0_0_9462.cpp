#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> monitored;

bool hasCycle(int start, int length, vector<bool>& visited) {
    if (length % 2 == 0) {
        return false;
    }

    if (visited[start]) {
        return true;
    }

    visited[start] = true;

    for (int next : graph[start]) {
        if (!monitored[next] && hasCycle(next, length + 1, visited)) {
            return true;
        }
    }

    visited[start] = false;
    return false;
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    graph.resize(N + 1);
    monitored.resize(M + 1, false);

    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(i);
        graph[v].push_back(i);
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;

        for (int j = l; j <= r; j++) {
            monitored[j] = true;
        }

        vector<bool> visited(N + 1, false);
        bool canExecute = false;

        for (int j = 1; j <= N; j++) {
            if (hasCycle(j, 1, visited)) {
                cout << "YES" << endl;
                canExecute = true;
                break;
            }
        }

        if (!canExecute) {
            cout << "NO" << endl;
        }

        for (int j = l; j <= r; j++) {
            monitored[j] = false;
        }
    }

    return 0;
}