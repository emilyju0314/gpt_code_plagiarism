#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define f first
#define s second

int main() {
    int t, T, n, m;
    cin >> t >> T >> n >> m;

    vector<pair<int, int>> teachers(n);
    for(int i = 0; i < n; i++) {
        cin >> teachers[i].f >> teachers[i].s;
    }

    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> color(n, -1);
    queue<int> q;

    color[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : graph[v]) {
            if (color[u] == -1) {
                color[u] = 1 - color[v];
                q.push(u);
            } else if (color[u] == color[v]) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    int num_group_1 = 0;
    int num_group_2 = 0;

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            num_group_1++;
        } else {
            num_group_2++;
        }
    }

    int max_num_group_1 = min(t, T - num_group_2);
    int min_num_group_1 = max(t, T - num_group_2);

    if (num_group_1 >= min_num_group_1 && num_group_1 <= max_num_group_1) {
        cout << "POSSIBLE" << endl;
        cout << min_num_group_1 << " " << num_group_2 << endl;
        for (int i = 0; i < n; i++) {
            cout << color[i] + 1;
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}