#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int a, b, color;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    vector<vector<pair<int, int>>> adj(N + 1);

    for (int i = 0; i < M; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].color;
        adj[edges[i].a].push_back({edges[i].b, edges[i].color});
        adj[edges[i].b].push_back({edges[i].a, edges[i].color});
    }

    vector<int> black_counts(N + 1, 0), red_counts(N + 1, 0);
    for (const Edge& edge : edges) {
        if (edge.color == 1) {
            black_counts[edge.a]++;
            black_counts[edge.b]++;
        } else {
            red_counts[edge.a]++;
            red_counts[edge.b]++;
        }
    }

    vector<double> values(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (black_counts[i] == 0) {
            values[i] = 1.0;
        } else if (red_counts[i] == 0) {
            values[i] = 2.0;
        }
    }

    cout << "YES" << endl;
    for (int i = 1; i <= N; i++) {
        if (values[i] == 0) {
            double sum = 0;
            for (const auto& neighbor : adj[i]) {
                sum += values[neighbor.first] - (neighbor.second == 1 ? 1.0 : 2.0);
            }
            values[i] = sum / black_counts[i];
        }
        cout << values[i] << " ";
    }
    cout << endl;

    return 0;
}