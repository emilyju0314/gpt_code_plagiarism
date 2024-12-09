#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> rank;

int find(int x) {
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (rank[x] < rank[y]) {
        swap(x, y);
    }

    parent[y] = x;
    rank[x] += rank[y];
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n);
    rank.resize(n, 1);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int last = 0;
    while (m--) {
        int type, x, y;
        cin >> type >> x >> y;
        x = (x + last - 1) % n;
        y = (y + last - 1) % n;

        if (type == 1) {
            unite(x, y);
        } else {
            last = (find(x) == find(y)) ? 1 : 0;
            cout << last;
        }
    }

    return 0;
}