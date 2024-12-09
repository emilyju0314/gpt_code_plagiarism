#include <iostream>
#include <vector>

using namespace std;

// Union-Find data structure
class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return;
        }

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        uf.unite(a-1, b-1);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (uf.find(i) == i) {
            count++;
        }
    }

    cout << count - 1 << endl;

    return 0;
}