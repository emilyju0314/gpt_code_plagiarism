#include <iostream>
#include <vector>

using namespace std;

int query(int u, int v, int w) {
    cout << "? " << u << " " << v << " " << w << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int main() {
    int h;
    cin >> h;

    vector<int> nodes;
    for (int i = 1; i < (1 << h); i++) {
        nodes.push_back(i);
    }

    int u = nodes[0];
    int v = nodes[1];

    // Find node with height h - 1 that is an ancestor of both u and v
    int w = 1;
    for (int i = 2; i < (1 << h); i++) {
        int x = query(u, v, nodes[i]);
        if (x == nodes[i]) {
            w = nodes[i];
            break;
        }
    }

    // Find the root node
    int root = w;
    for (int i = h - 2; i >= 0; i--) {
        int x = query(root, nodes[(1 << i) - 1], w);
        if (x != w) {
            root = x;
        }
    }

    cout << "! " << root << endl;
    cout.flush();

    return 0;
}