#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--; // adjust 1-based index to 0-based index
        u--;
        adj[v][u] = 1;
        adj[u][v] = 1;
    }

    vector<int> safe_count(n, 0);

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][k] && adj[k][j]) {
                    if (adj[i][k] == 1 && adj[k][j] == 1 && adj[i][j] == 0) {
                        safe_count[k]++;
                    }
                }
            }
        }
    }

    double ans = 0.0;

    for (int i = 0; i < n; i++) {
        double total_safe = 0;

        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                total_safe += safe_count[j];
            }
        }

        ans = max(ans, total_safe / (n - 2));
    }

    cout << fixed;
    cout.precision(12);
    cout << ans << endl;

    return 0;
}