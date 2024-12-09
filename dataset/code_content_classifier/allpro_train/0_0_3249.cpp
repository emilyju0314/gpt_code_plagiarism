#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    double res = 0.0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<int> dist(n, n + 1);
            dist[i] = 0;
            dist[j] = 1;

            for (int k = 0; k < n; k++) {
                for (int a = 0; a < n; a++) {
                    for (int b = 0; b < n; b++) {
                        if (adj[a][b] == 1) {
                            dist[b] = min(dist[b], dist[a] + 1);
                        }
                    }
                }
            }

            double p_win = 0.0;

            for (int a = 0; a < n; a++) {
                if (a != i && a != j) {
                    // Limak is in city a
                    p_win += 1.0 / (n - 2) * (dist[a] < dist[j]);
                }
            }

            res = max(res, p_win);
        }
    }

    cout << fixed << setprecision(12) << res << endl;

    return 0;
}