#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> depth;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    
    if (x == y) return;
    
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    
    parent[y] = x;
    
    if (depth[x] == depth[y]) {
        depth[x]++;
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    parent.resize(n + 1);
    depth.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    
    for (int i = 0; i < q; i++) {
        int type, x, y;
        cin >> type >> x;
        
        if (type == 1) {
            cout << depth[find(x)] << endl;
        } else {
            cin >> y;
            merge(x, y);
        }
    }
    
    return 0;
}