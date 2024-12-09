#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L;
    cin >> L;

    int N = L + 1;
    int M = 2 * N - 1;

    vector<vector<int>> graph;
    for (int i = 0; i < N; i++) {
        vector<int> row(N, 0);
        graph.push_back(row);
    }

    for (int i = 1; i < N; i++) {
        graph[i - 1][i] = 0;
        graph[i][i - 1] = 0;
    }

    for (int i = 1; i < N - 1; i++) {
        int len = i - 1;
        graph[i][i + 1] = len;
        graph[i + 1][i] = 0;
    }

    cout << N << " " << M << endl;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (graph[i][j] > 0) {
                cout << i+1 << " " << j+1 << " " << graph[i][j] << endl;
            }
        }
    }

    return 0;
}