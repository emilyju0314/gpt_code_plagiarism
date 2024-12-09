#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;
    vector<pair<int, int>> included_edges;
    vector<pair<int, int>> excluded_edges;

    for (int i = 0; i < m; i++) {
        int weight, included;
        cin >> weight >> included;
        edges.push_back({weight, {included, i}});
        if (included == 1) {
            included_edges.push_back({weight, i});
        } else {
            excluded_edges.push_back({weight, i});
        }
    }

    sort(edges.begin(), edges.end());

    // Check if the given information is valid
    if (included_edges.size() != n - 1) {
        cout << -1 << endl;
    } else {
        int current_vertex = 1;
        for (int i = 0; i < n - 1; i++) {
            cout << current_vertex << " " << current_vertex + 1 << endl;
            current_vertex++;
        }

        for (auto edge : excluded_edges) {
            cout << current_vertex << " " << current_vertex + 1 << endl;
            current_vertex++;
        }
    }

    return 0;
}