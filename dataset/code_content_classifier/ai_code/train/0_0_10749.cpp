#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    vector<vector<int>> edges(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        edges[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> edges[i][j];
        }
    }

    int q;
    cin >> q;

    for (int query = 0; query < q; query++) {
        int x, y;
        cin >> x >> y;
        x--; // 0-based indexing

        unordered_set<int> visited;
        vector<int> count(n, 0);
        int current_vertex = x;
        int current_val = y;

        while (visited.find(current_vertex) == visited.end()) {
            visited.insert(current_vertex);
            count[current_vertex]++;
            current_val += k[current_vertex];
            current_vertex = edges[current_vertex][current_val % edges[current_vertex].size()];
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > 1) {
                total++;
            }
        }

        cout << total << endl;
    }

    return 0;
}