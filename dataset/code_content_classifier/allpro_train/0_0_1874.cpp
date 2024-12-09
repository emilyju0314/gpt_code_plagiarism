#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dist(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool possible = true;
            for (int l = 0; l < k; l++) {
                if (dist[l][i] + dist[l][j] > n - 1) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                edges.push_back({i+1, j+1});
            }
        }
    }

    if (edges.size() < n - 1) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n - 1; i++) {
            cout << edges[i].first << " " << edges[i].second << endl;
        }
    }

    return 0;
}