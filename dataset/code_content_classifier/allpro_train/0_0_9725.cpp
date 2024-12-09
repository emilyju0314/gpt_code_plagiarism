#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        graph[v].push_back({u, w});
        graph[u].push_back({v, w});
    }

    int l;
    cin >> l;

    vector<int> distance(n + 1, -1);
    queue<int> q;

    distance[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto neighbor : graph[curr]) {
            int next = neighbor.first;
            int weight = neighbor.second;

            if (distance[next] == -1) {
                distance[next] = distance[curr] + weight;
                q.push(next);
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (distance[i] == l) {
            count++;
        } else {
            for (auto neighbor : graph[i]) {
                int neighbor_city = neighbor.first;
                int road_length = neighbor.second;

                if ((distance[i] < l && distance[neighbor_city] > l) || (distance[i] > l && distance[neighbor_city] < l)) {
                    int total_distance = abs(distance[i] - l) + abs(distance[neighbor_city] - l);
                    if (total_distance == road_length) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}