#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v;
};

bool compare(Edge e1, Edge e2) {
    return e1.u < e2.u;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({min(a, b), max(a, b)});
    }

    sort(edges.begin(), edges.end(), compare);

    long long ans = 0;
    int first = edges[0].u;
    for (int i = 1; i < m; i++) {
        if (edges[i].u != first) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}