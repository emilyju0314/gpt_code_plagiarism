#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int q;
    cin >> q;

    int last = 0;
    unordered_map<int, int> parent;
    unordered_map<int, int> xor_vals;
    
    auto root = [&](int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            xor_vals[x] = 0;
            return x;
        } else if (parent[x] == x) {
            return x;
        } else {
            int p = root(parent[x]);
            xor_vals[x] ^= xor_vals[parent[x]];
            return parent[x] = p;
        }
    };

    auto merge = [&](int x, int y, int val) {
        int root_x = root(x);
        int root_y = root(y);
        if (root_x != root_y) {
            parent[root_x] = root_y;
            xor_vals[root_x] = xor_vals[x] ^ xor_vals[y] ^ val;
        }
    };

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l ^= last;
            r ^= last;
            x ^= last;
            if (l > r) swap(l, r);
            merge(l, r + 1, x);
        } else {
            int l, r;
            cin >> l >> r;
            l ^= last;
            r ^= last;
            if (l > r) swap(l, r);
            if (root(l) != root(r + 1)) {
                cout << -1 << endl;
                last = 1;
            } else {
                cout << (xor_vals[l] ^ xor_vals[r + 1]) << endl;
                last = xor_vals[l] ^ xor_vals[r + 1];
            }
        }
    }

    return 0;
}