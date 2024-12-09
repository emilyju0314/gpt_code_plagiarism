#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> node_values(n);
    for(int i = 0; i < n; i++) {
        cin >> node_values[i];
    }

    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a-1, b-1}});
    }

    sort(edges.rbegin(), edges.rend()); // Sort edges in decreasing order of value

    double max_density = 0.0;

    for (int i = 0; i < m; i++) {
        vector<bool> visited(n, false);
        visited[edges[i].second.first] = true;
        visited[edges[i].second.second] = true;

        double sum_node_values = node_values[edges[i].second.first] + node_values[edges[i].second.second];
        double sum_edge_values = edges[i].first;

        for (int j = 0; j < m; j++) {
            if (visited[edges[j].second.first] != visited[edges[j].second.second]) { // Check if adding this edge connects the induced subgraph
                visited[edges[j].second.first] = true;
                visited[edges[j].second.second] = true;
                sum_node_values += node_values[edges[j].second.first] + node_values[edges[j].second.second];
                sum_edge_values += edges[j].first;
            }

            double density = sum_node_values / sum_edge_values;
            max_density = max(max_density, density);
        }
    }

    cout << fixed << setprecision(9) << max_density << endl;

    return 0;
}