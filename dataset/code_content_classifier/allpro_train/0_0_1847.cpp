#include <iostream>
#include <vector>

using namespace std;

int parent[101];

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= 100; i++) {
        parent[i] = i;
    }

    vector<pair<int, int>> snow_drifts;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        snow_drifts.push_back({x, y});
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (snow_drifts[i].first == snow_drifts[j].first ||
                snow_drifts[i].second == snow_drifts[j].second) {
                unite(i + 1, j + 1);
            }
        }
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            components++;
        }
    }

    cout << components - 1 << endl;

    return 0;
}