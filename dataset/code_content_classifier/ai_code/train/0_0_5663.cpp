#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> marked(k);
    set<int> markedSet; // to easily check if a vertex is marked
    for (int i = 0; i < k; i++) {
        cin >> marked[i];
        markedSet.insert(marked[i]);
    }

    // if there are less than 2 marked vertexes, or all marked vertexes are connected,
    // then Valera's code will work correctly
    if (k < 2 || n-1 < k) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++) {
        if (markedSet.find(i) == markedSet.end()) {
            edges.push_back({i, marked[0]});
            markedSet.insert(i);
            if (edges.size() == m) break;
        }
    }

    if (edges.size() < m) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < m; i++) {
            cout << edges[i].first << " " << edges[i].second << endl;
        }
    }

    return 0;
}