#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, p;
        cin >> n >> p;

        vector<pair<int, int>> edges;

        for (int j = 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                edges.push_back({j, k});
            }
        }

        int edgeCount = 2*n + p;
        for (int j = 0; j < edgeCount; j++) {
            cout << edges[j].first << " " << edges[j].second << endl;
        }
    }

    return 0;
}