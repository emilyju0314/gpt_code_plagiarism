#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(vector<vector<int>>& adjList, int start, vector<int>& distances) {
    queue<int> q;
    q.push(start);
    distances[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : adjList[curr]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[curr] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> adjList(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since the graph is undirected
    }

    vector<int> distances(N, -1);
    bfs(adjList, 0, distances);

    for (int i = 0; i < N; i++) {
        cout << distances[i] << endl;
    }

    return 0;
}