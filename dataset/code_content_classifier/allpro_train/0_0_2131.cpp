#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> colors(n, {0, 0});
    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if ((x1 + y1) % 2 == 0) {
            colors[i] = {1, 0};
        } else {
            colors[i] = {2, 0};
        }
        adjList[i] = {};
        
        for (int j = 0; j < i; j++) {
            if ((abs(x1 - x2) + abs(y1 - y2) + abs(colors[i].first - colors[j].first)) % 2 == 0) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    vector<int> color(n, 0);
    vector<bool> visited(n, false);
    stack<int> s;

    for (int start = 0; start < n; start++) {
        if (!visited[start]) {
            s.push(start);
            color[start] = colors[start].first;
        }
        
        while (!s.empty()) {
            int u = s.top();
            s.pop();
            visited[u] = true;

            for (int v : adjList[u]) {
                if (!visited[v]) {
                    color[v] = (color[u] == colors[v].first) ? colors[v].second : colors[v].first;
                    s.push(v);
                }
            }
        }
    }

    cout << "YES" << endl;
    for (int c : color) {
        cout << c << endl;
    }

    return 0;
}