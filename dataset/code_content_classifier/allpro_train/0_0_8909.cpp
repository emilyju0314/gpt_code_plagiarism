#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 300;
int n, a[MAXN][MAXN];

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cin >> a[i][j];
                a[j][i] = a[i][j];
            }
        }

        int minCost = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int cost = 0;
            vector<bool> red(n, false);
            vector<int> dist(n, INT_MAX);

            for (int j = 0; j < n; ++j) {
                dist[j] = a[i][j];
            }

            dist[i] = 0;
            red[i] = true;

            for (int j = 0; j < n - 1; ++j) {
                int u = -1;
                for (int k = 0; k < n; ++k) {
                    if (!red[k] && (u == -1 || dist[k] < dist[u])) {
                        u = k;
                    }
                }

                cost += dist[u];
                red[u] = true;

                for (int k = 0; k < n; ++k) {
                    if (!red[k] && a[u][k] < dist[k]) {
                        dist[k] = a[u][k];
                    }
                }
            }

            minCost = min(minCost, cost);
        }

        cout << (minCost == INT_MAX ? -1 : minCost) << endl;
    }

    return 0;
}