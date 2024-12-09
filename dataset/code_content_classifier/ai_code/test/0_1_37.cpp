#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> edges;
        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        for (int i = 0; i < n-1; i++) {
            cout << edges[i].first << " " << edges[i].second << endl;
        }
    }

    return 0;
}