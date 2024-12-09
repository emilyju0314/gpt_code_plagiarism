#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Cable {
    int a, b, length, effort;
};

struct DSU {
    vector<int> parent, size;
    int components;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        components = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            components--;
        }
    }
};

bool compareCables(const Cable& c1, const Cable& c2) {
    return c1.effort * c2.length < c2.effort * c1.length;
}

double calculateFeelingOfHumor(vector<Cable>& cables, int n) {
    sort(cables.begin(), cables.end(), compareCables);
    DSU dsu(n);
    double totalLength = 0, totalEffort = 0;

    for (const Cable& cable : cables) {
        if (dsu.find(cable.a) != dsu.find(cable.b)) {
            dsu.unite(cable.a, cable.b);
            totalLength += cable.length;
            totalEffort += cable.effort;
        }
    }

    if (dsu.components > 1) return 0;
    return totalLength / totalEffort;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Cable> cables(m);
    for (int i = 0; i < m; i++) {
        cin >> cables[i].a >> cables[i].b >> cables[i].length >> cables[i].effort;
    }

    double feelingOfHumor = calculateFeelingOfHumor(cables, n);
    cout << fixed << setprecision(5) << feelingOfHumor << endl;

    return 0;
}