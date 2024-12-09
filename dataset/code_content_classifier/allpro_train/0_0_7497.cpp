#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> iceCream(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int type;
            cin >> type;
            iceCream[i].insert(type);
        }
    }

    vector<vector<int>> tree(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }

    vector<int> colors(m, -1);
    map<pair<int, int>, int> edgeColors;
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int color = 1;
        for (int type : iceCream[u]) {
            if (colors[type-1] != -1) {
                color = max(color, colors[type-1] + 1);
            }
        }

        colors[u] = color;

        for (int v : tree[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;

                for (int type : iceCream[v]) {
                    if (colors[type-1] == -1) {
                        colors[type-1] = color;
                    } else {
                        edgeColors[{min(color, colors[type-1]), max(color, colors[type-1])}] = 1;
                    }
                }
            }
        }
    }

    int c = 1;
    for (int i = 0; i < m; i++) {
        c = max(c, colors[i]);
    }

    cout << c << endl;
    for (int i = 0; i < m; i++) {
        cout << colors[i] << " ";
    }

    return 0;
}