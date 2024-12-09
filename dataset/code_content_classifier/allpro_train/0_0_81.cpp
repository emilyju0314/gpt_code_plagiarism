#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> performance(N);
    for (int i = 0; i < N; i++) {
        cin >> performance[i];
    }

    vector<vector<int>> graph(N, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u][v] = performance[u] + performance[v];
        graph[v][u] = performance[u] + performance[v];
    }

    vector<int> result(N);

    for (int i = 0; i < N; i++) {
        int total_performance = 0;
        for (int j = 0; j < N; j++) {
            if (j == i) continue;
            total_performance += graph[i][j];
        }
        result[i] = total_performance;
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << endl;
    }

    return 0;
}