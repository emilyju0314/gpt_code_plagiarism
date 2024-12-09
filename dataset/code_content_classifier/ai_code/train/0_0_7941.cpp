#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long A, B, C;
    cin >> A >> B >> C;

    vector<vector<int>> conflicts(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        conflicts[u][v] = conflicts[v][u] = 1;
    }

    long long totalSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (!conflicts[i][j] && !conflicts[j][k] && !conflicts[k][i]) {
                    totalSum += (A*i + B*j + C*k);
                }
            }
        }
    }

    cout << totalSum << endl;

    return 0;
}