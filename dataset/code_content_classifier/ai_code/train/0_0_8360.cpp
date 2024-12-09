#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int a, b, m;
    cin >> a >> b >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges[i] = {x, y};
    }

    vector<int> colors(m);
    unordered_map<int, unordered_set<int>> adjList;
    for (int i = 0; i < m; i++) {
        adjList[edges[i].first].insert(i);
        adjList[edges[i].second + a].insert(i);
    }

    int max_degree = 0;
    for (auto it : adjList) {
        max_degree = max(max_degree, (int)it.second.size());
    }

    cout << max_degree << endl;

    vector<int> color_map;
    queue<int> q;
    for (auto it : adjList) {
        if (it.second.size() == max_degree) {
            q.push(it.first);
            for (int edge : it.second) {
                colors[edge] = q.size();
            }
        }
    }

    int color = max_degree;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int edge : adjList[u]) {
            int v = edges[edge].first + edges[edge].second - u;
            if (adjList[v].size() == max_degree) {
                color++;
                for (int edge2 : adjList[v]) {
                    if (colors[edge2] == 0) {
                        colors[edge2] = color;
                    }
                }
                q.push(v);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;

    return 0;
}