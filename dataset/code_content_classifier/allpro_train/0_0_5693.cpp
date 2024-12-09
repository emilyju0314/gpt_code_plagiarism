#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adjList(N+1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    int S, T;
    cin >> S >> T;

    vector<bool> visited(N+1, false);
    vector<int> distance(N+1, -1);

    queue<int> q;
    q.push(S);
    visited[S] = true;
    distance[S] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int neighbor : adjList[curr]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                distance[neighbor] = distance[curr] + 1;
            }
        }
    }

    cout << distance[T] << endl;

    return 0;
}