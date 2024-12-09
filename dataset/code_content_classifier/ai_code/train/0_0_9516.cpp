#include <iostream>
#include <vector>

using namespace std;

struct Bridge {
    int destination;
    int time;
};

int dfs(int node, vector<vector<Bridge>>& graph, vector<bool>& visited) {
    int totalTime = 0;
    visited[node] = true;
    for (Bridge& b : graph[node]) {
        if (!visited[b.destination]) {
            totalTime += b.time + dfs(b.destination, graph, visited);
        }
    }
    return totalTime;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<vector<Bridge>> graph(N);
        for (int i = 0; i < N - 1; ++i) {
            int a, b, t;
            cin >> a >> b >> t;
            graph[a - 1].push_back({b - 1, t});
            graph[b - 1].push_back({a - 1, t});
        }

        vector<bool> visited(N, false);
        int totalTime = dfs(0, graph, visited);
        cout << totalTime << endl;
    }

    return 0;
}