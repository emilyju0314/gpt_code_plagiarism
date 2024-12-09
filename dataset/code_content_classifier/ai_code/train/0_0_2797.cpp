#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;

    int n = 3 + 2 * k; // Number of vertices
    cout << n << endl;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 1; i <= 3; i++) {
        for (int j = i + 1; j <= 3; j++) {
            graph[i][j] = graph[j][i] = 1;
        }
    }

    for (int i = 4; i < n; i++) {
        graph[i][i+1] = graph[i+1][i] = 1;
        graph[i][i+2] = graph[i+2][i] = 1;
        graph[i+1][i+2] = graph[i+2][i+1] = 1;
    }

    // Print graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }

    return 0;
}