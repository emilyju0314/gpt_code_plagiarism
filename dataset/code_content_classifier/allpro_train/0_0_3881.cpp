#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> visited(N + 1, false);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    vector<int> path;

    int curr = 1;
    path.push_back(curr);
    visited[curr] = true;

    while (true) {
        bool found = false;
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                path.push_back(neighbor);
                visited[neighbor] = true;
                curr = neighbor;
                found = true;
                break;
            }
        }

        if (!found) {
            break;
        }
    }

    cout << path.size() << endl;
    for (int vertex : path) {
        cout << vertex << " ";
    }

    return 0;
}