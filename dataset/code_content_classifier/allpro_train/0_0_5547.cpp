#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int q;
    cin >> q;

    vector<int> parent(1<<30); // For Union-Find
    vector<int> xorVal(1<<30); // Stores the XOR value
    vector<int> size(1<<30, 1); // Size of each component
    
    unordered_map<int, int> compress;

    int last = 0;

    for(int i = 0; i < (1<<30); i++) {
        parent[i] = i;
        xorVal[i] = 0;
        compress[i] = i;
    }

    auto root = [&](int v) {
        if(v == parent[v])
            return v;
        return parent[v] = root(parent[v]);
    };

    auto merge = [&](int a, int b, int x) {
        a = root(a);
        b = root(b);
        if(size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        xorVal[b] = xorVal[a] ^ xorVal[b] ^ x;
        size[a] += size[b];
    };

    auto query = [&](int a, int b) {
        if(root(a) != root(b))
            return -1;
        return xorVal[a] ^ xorVal[b];
    };

    while(q--) {
        int t;
        cin >> t;
        
        if(t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l ^= last;
            r ^= last;
            x ^= last;

            if(l > r)
                swap(l, r);

            l = root(compress[l]);
            r = root(compress[r]);

            if(l != r)
                merge(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            l ^= last;
            r ^= last;

            if(l > r)
                swap(l, r);

            l = root(compress[l]);
            r = root(compress[r]);

            last = query(l, r);
            cout << last << endl;
            if(last == -1) last = 1;
        }
    }

    return 0;
}