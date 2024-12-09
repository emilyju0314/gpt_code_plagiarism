#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            adj[i][j] = line[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                for (int k = 0; k < n; k++) {
                    if (adj[j][k] == 1 && adj[k][i] == 1) {
                        cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}