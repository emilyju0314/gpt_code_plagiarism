#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int MAXN = 100005;

int parent[MAXN];
double prob[MAXN];
int size[MAXN];

int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        cin >> prob[i];
    }

    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int q;
    cin >> q;

    vector<pair<int, double>> changes;
    for (int i = 0; i < q; i++) {
        int planet;
        double new_prob;
        cin >> planet >> new_prob;
        changes.push_back({planet, new_prob});
    }

    vector<double> result;
    double ans = n;
    result.push_back(ans);

    for (int i = q - 1; i >= 0; i--) {
        int planet = changes[i].first;
        double new_prob = changes[i].second;

        double old_prob = prob[planet];
        prob[planet] = new_prob;

        for (auto& edge : edges) {
            int u = edge.first;
            int v = edge.second;

            if (prob[u] >= prob[v]) {
                unite(u, v);
            }
        }

        ans -= (size[find(planet)] - 1) * old_prob;
        ans += (size[find(planet)] - 1) * new_prob;

        result.push_back(ans);
    }

    for (int i = q - 1; i >= 0; i--) {
        cout << fixed << setprecision(5) << result[i] << endl;
    }

    return 0;
}