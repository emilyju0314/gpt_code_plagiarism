#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

struct Edge {
    int from, to, cost, time;
};

int main() {
    int n, m;

    while (cin >> n >> m && n != 0 && m != 0) {
        vector<Edge> edges(n);

        for (int i = 0; i < n; i++) {
            cin >> edges[i].from >> edges[i].to >> edges[i].cost >> edges[i].time;
        }

        int k;
        cin >> k;

        for (int i = 0; i < k; i++) {
            int p, q, r;
            cin >> p >> q >> r;

            vector<int> dist(m + 1, INT_MAX);
            vector<int> time(m + 1, INT_MAX);

            dist[p] = time[p] = 0;

            for (int j = 0; j < m - 1; j++) {
                for (auto edge : edges) {
                    if (dist[edge.from] != INT_MAX) {
                        dist[edge.to] = min(dist[edge.to], dist[edge.from] + edge.cost);
                        time[edge.to] = min(time[edge.to], time[edge.from] + edge.time);
                    }
                    if (dist[edge.to] != INT_MAX) {
                        dist[edge.from] = min(dist[edge.from], dist[edge.to] + edge.cost);
                        time[edge.from] = min(time[edge.from], time[edge.to] + edge.time);
                    }
                }
            }

            if (r == 0) {
                cout << dist[q] << endl;
            } else {
                cout << time[q] << endl;
            }
        }
    }

    return 0;
}