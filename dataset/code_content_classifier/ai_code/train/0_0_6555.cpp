#include <iostream>
#include <vector>

using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return (parent[x] == x) ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y]) {
                swap(x, y);
            }
            size[x] += size[y];
            parent[y] = x;
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    DSU dsu(N);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        dsu.unite(A - 1, B - 1);
    }

    int components = 0;
    for (int i = 0; i < N; i++) {
        if (dsu.find(i) == i) {
            components++;
        }
    }

    int additional_roads = components - 1;
    cout << additional_roads << endl;

    return 0;
}