#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    vector<pair<int, int>> edges;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= d[i-1]; j++) {
            if (i + j <= n) {
                edges.push_back({i, i + j});
            }
        }
    }

    cout << edges.size() << endl;
    for (auto edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}