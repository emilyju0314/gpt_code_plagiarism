#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>(n, 0));
    vector<vector<double>> flow(n, vector<double>(n));
    vector<int> cap(m);
    vector<int> u(m), v(m);

    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> cap[i];
        u[i]--; v[i]--;
        adj[u[i]][v[i]] += cap[i];
        adj[v[i]][u[i]] += cap[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            flow[j][i] = flow[i][j] = adj[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                flow[i][j] = min(flow[i][j], max(flow[i][k], flow[k][j]));
            }
        }
    }

    double maxFlow = flow[0][n - 1];

    cout << fixed << setprecision(5) << maxFlow << endl;

    for (int i = 0; i < m; i++) {
        if (flow[u[i]][v[i]] > flow[v[i]][u[i]]) {
            cout << fixed << setprecision(5) << cap[i] - (flow[n-1][0] - flow[v[i]][u[i]]) << endl;
        } else {
            cout << fixed << setprecision(5) << cap[i] + flow[v[i]][u[i]] << endl;
        }
    }

    return 0;
}