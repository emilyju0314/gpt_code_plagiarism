#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> degrees(n);
    int max_degree = 0;
    int max_deg_vertex = -1;

    for (int i = 0; i < n; i++) {
        cin >> degrees[i];
        if (degrees[i] > max_degree) {
            max_degree = degrees[i];
            max_deg_vertex = i;
        }
    }

    if (max_degree >= n) {
        cout << "NO" << endl;
        return 0;
    }

    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        if (i != max_deg_vertex) {
            edges.push_back({i, max_deg_vertex});
            degrees[i]--;
            degrees[max_deg_vertex]--;
        }
    }

    for (int i = 1; i < n; i++) {
        if (degrees[i] < 0) {
            cout << "NO" << endl;
            return 0;
        }
        while (degrees[i] > 0) {
           edges.push_back({i, i-1});
           degrees[i]--;
           degrees[i-1]--;
        }
    }

    cout << "YES" << endl;
    cout << n - 1 << endl;
    for (auto edge : edges) {
        cout << edge.first + 1 << " " << edge.second + 1 << endl;
    }

    return 0;
}