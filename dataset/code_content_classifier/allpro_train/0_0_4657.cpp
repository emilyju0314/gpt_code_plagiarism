#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1);
    vector<int> parent(N + 1, 0);
    vector<long long> dist(N + 1);
    vector<long long> edge_lengths(N + 1);

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        cin >> dist[i];
    }

    for (int i = 2; i <= N; i++) {
        if (i == 2) {
            edge_lengths[i] = dist[i];
        } else {
            edge_lengths[parent[i]] = dist[i] - dist[parent[i]];
        }

        for (auto child: graph[i]) {
            parent[child] = i;
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << edge_lengths[i] << endl;
    }

    return 0;
}