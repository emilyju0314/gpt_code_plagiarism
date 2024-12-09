#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    UnionFind uf(M);

    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        vector<int> languages(K);
        for (int j = 0; j < K; j++) {
            cin >> languages[j];
            languages[j]--;
        }
        for (int j = 1; j < K; j++) {
            uf.unite(languages[j-1], languages[j]);
        }
    }

    int root = uf.find(0);
    for (int i = 1; i < M; i++) {
        if (uf.find(i) != root) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}