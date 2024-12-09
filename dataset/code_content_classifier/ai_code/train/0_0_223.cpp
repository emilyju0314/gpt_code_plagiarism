#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int v;
            cin >> v;
            graph[i].push_back(v);
        }
    }

    int s;
    cin >> s;

    vector<int> result;
    vector<int> visited(n+1, 0);

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        visited[u] = 1;
        for (int v : graph[u]) {
            if (visited[v] == 0) {
                q.push(v);
            }
        }

        result.push_back(u);
    }

    if (result.size() <= m) {
        cout << "Lose" << endl;
    } else {
        result.pop_back();
        cout << "Win" << endl;
        for (int u : result) {
            cout << u << " ";
        }
        cout << endl;
    }

    return 0;
}