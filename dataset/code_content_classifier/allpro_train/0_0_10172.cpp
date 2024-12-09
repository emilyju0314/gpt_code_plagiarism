#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Edge {
    int from, to, value;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> node_values(n);
    for (int i = 0; i < n; i++) {
        cin >> node_values[i];
    }

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].value;
    }

    double max_density = 0.0;
    for (int i = 0; i < m; i++) {
        double density = static_cast<double>(node_values[edges[i].from - 1] + node_values[edges[i].to - 1]) / edges[i].value;
        max_density = max(max_density, density);
    }

    cout << fixed << setprecision(9) << max_density << endl;

    return 0;
}