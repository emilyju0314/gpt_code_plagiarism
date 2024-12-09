#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    vector<int> deleted(n);
    vector<long long> shortest_paths(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> deleted[i];
        deleted[i]--;
    }

    for (int i = n-1; i >= 0; i--) {
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                graph[a][b] = min(graph[a][b], graph[a][deleted[i]] + graph[deleted[i]][b]);
            }
        }

        long long sum = 0;
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                sum += graph[a][b];
            }
        }

        cout << sum << " ";
    }

    return 0;
}