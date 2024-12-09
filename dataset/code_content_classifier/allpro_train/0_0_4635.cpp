#include <iostream>
#include <vector>
#include <set>

using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    while (m--) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        dsu.unite(u, v);
    }

    set<int> div1;
    set<int> div2;

    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i) {
            div1.insert(i);
            div2.insert(i);
        }
    }

    long long ways = 1;
    for (int i = 0; i < n; i++) {
        if (dsu.find(i) != i) {
            if (dsu.find(i) == dsu.find(*div1.begin())) {
                div1.insert(i);
            } else {
                div2.insert(i);
            }
        }
    }

    cout << div1.size() * div2.size() - m << endl;

    return 0;
}