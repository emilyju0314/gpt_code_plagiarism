#include <iostream>
#include <vector>

using namespace std;

bool canWin(vector<vector<int>>& graph, vector<bool>& visited, int fault) {
    for (int nextFault : graph[fault]) {
        if (!visited[nextFault]) {
            visited[nextFault] = true;
            if (canWin(graph, visited, nextFault)) {
                return true;
            }
            visited[nextFault] = false;
        }
    }
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    for (int i = 1; i <= N; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            int b;
            cin >> b;
            graph[i].push_back(b);
        }
    }

    vector<bool> visited(M + 1, false);

    for (int i = 1; i <= N; i++) {
        visited[i] = true;
        if (!canWin(graph, visited, i)) {
            cout << "Alice" << endl;
            return 0;
        }
        visited[i] = false;
    }

    cout << "Bob" << endl;

    return 0;
}