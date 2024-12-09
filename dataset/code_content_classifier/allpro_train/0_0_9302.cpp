#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int u, v, weight;
};

int find(vector<int> &parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void unite(vector<int> &parent, vector<int> &rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY]) {
            rank[rootY]++;
        }
    }
}

int main() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    vector<Edge> roads(m);
    for (int i = 0; i < m; i++) {
        cin >> roads[i].u >> roads[i].v >> roads[i].weight;
    }

    sort(roads.begin(), roads.end(), [](const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    });

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int totalLength = 0;
    int regions = n;
    for (int i = 0; i < m; i++) {
        int u = roads[i].u;
        int v = roads[i].v;
        int weight = roads[i].weight;

        if (find(parent, u) != find(parent, v)) {
            if (regions == q) {
                break;
            }
            unite(parent, rank, u, v);
            regions--;
            totalLength += weight;
        }
    }

    if (regions > q || (regions > 1 && q == 1)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            if (find(parent, i) != find(parent, 1)) {
                cout << 1 << " " << i << endl;
                p--;
                if (p == 0) {
                    break;
                }
            }
        }
    }

    return 0;
}