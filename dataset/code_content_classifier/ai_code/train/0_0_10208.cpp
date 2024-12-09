#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge {
    int to;
    int length;
};

int main() {
    int C, W;

    while (true) {
        cin >> C >> W;
        if (C == 0 && W == 0) break;

        vector<vector<Edge>> graph(C);
        vector<int> in_degree(C, 0);

        vector<pair<int, int>> pillars(C);
        for (int i = 0; i < C; i++) {
            int x, y;
            cin >> x >> y;
            pillars[i] = {x, y};
        }

        for (int i = 0; i < W; i++) {
            int s, t;
            cin >> s >> t;
            s--;
            t--;

            int length = abs(pillars[s].first - pillars[t].first) + abs(pillars[s].second - pillars[t].second);

            graph[s].push_back({t, length});
            graph[t].push_back({s, length});

            in_degree[s]++;
            in_degree[t]++;
        }

        // Use topological sorting to find the longest path in the graph
        queue<int> q;
        for (int i = 0; i < C; i++) {
            if (in_degree[i] == 1) {
                q.push(i);
            }
        }

        vector<int> max_length(C, 0);
        int res = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const Edge& edge : graph[u]) {
                int v = edge.to;
                int length = max_length[u] + edge.length;

                if (length > max_length[v]) {
                    max_length[v] = length;
                    res = max(res, length);
                }

                in_degree[v]--;
                if (in_degree[v] == 1) {
                    q.push(v);
                }
            }
        }

        cout << res / 2 << endl;
    }

    return 0;
}