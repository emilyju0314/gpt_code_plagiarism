#include <iostream>
#include <vector>

using namespace std;

bool isCyclic(vector<vector<int>>& adjMatrix, vector<int>& path, int v, vector<bool>& visited) {
    if (visited[v] && v == path[0]) {
        return true;
    }
    if (visited[v]) {
        return false;
    }

    visited[v] = true;
    path.push_back(v);

    for (int i = 0; i < adjMatrix.size(); i++) {
        if (adjMatrix[v][i] != 0) {
            if (isCyclic(adjMatrix, path, i, visited)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            adjMatrix[i][j] = rand() % 1000 + 1;
            adjMatrix[j][i] = adjMatrix[i][j];
        }
    }

    while (true) {
        if (!isCyclic(adjMatrix, vector<int>(), 0, visited)) {
            break;
        }

        visited = vector<bool>(n, false);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                adjMatrix[i][j] = rand() % 1000 + 1;
                adjMatrix[j][i] = adjMatrix[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}