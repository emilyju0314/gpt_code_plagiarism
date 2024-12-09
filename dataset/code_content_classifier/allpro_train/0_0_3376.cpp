#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> &parent, int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = find(parent, parent[x]);
    }
}

void unite(vector<int> &parent, int x, int y) {
    x = find(parent, x);
    y = find(parent, y);
    if (x != y) {
        parent[y] = x;
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < q; i++) {
        int command, x, y;
        cin >> command >> x >> y;

        if (command == 0) {
            unite(parent, x, y);
        } else {
            if (find(parent, x) == find(parent, y)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}