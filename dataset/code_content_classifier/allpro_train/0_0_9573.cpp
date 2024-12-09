#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> size;

int find(int x) {
    if (x == parent[x]) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    
    if (x != y) {
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < q; i++) {
        int type, x, y;
        cin >> type >> x >> y;
        
        if (type == 1) {
            merge(x, y);
        } else if (type == 2) {
            for (int j = x + 1; j <= y; j++) {
                merge(x, j);
            }
        } else {
            if (find(x) == find(y)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    
    return 0;
}