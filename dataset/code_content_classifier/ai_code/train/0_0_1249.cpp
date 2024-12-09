#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> days;
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int city = q.front();
        q.pop();

        days.push_back(city);

        for (auto neighbor : graph[city]) {
            if (!visited[neighbor.first]) {
                visited[neighbor.first] = true;
                q.push(neighbor.first);
            }
        }
    }

    if (days.size() != n) {
        cout << "Impossible" << endl;
    } else {
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << days[i] << " ";
        }
        cout << endl;
    }

    return 0;
}