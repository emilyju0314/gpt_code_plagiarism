#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 1; i <= n; i++) {
        cout << "? " << i << endl;
        cout.flush();

        for (int j = 1; j <= n; j++) {
            cin >> dist[i-1][j-1];
        }
    }

    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        int min_dist = *min_element(dist[i].begin(), dist[i].end());
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == min_dist) {
                edges.push_back({i+1, j+1});
            }
        }
    }

    cout << "!" << endl;
    for (int i = 0; i < n-1; i++) {
        cout << edges[i].first << " " << edges[i].second << endl;
    }

    return 0;
}