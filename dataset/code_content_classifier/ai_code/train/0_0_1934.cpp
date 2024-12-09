#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    if (n < 3 || m < n - 1 || v < 1 || v > n) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> connections;

    for (int i = 1; i <= n; i++) {
        if (i == v) continue;
        connections.push_back({v, i});
    }

    for (int i = 1; i < n; i++) {
        connections.push_back({i, i + 1});
    }

    for (int i = 0; i < m; i++) {
        cout << connections[i].first << " " << connections[i].second << endl;
    }

    return 0;
}