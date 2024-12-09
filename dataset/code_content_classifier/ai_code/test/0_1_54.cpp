#include <iostream>
#include <vector>
#include <map>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    
    UnionFind(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        UnionFind uf(n);
        map<pair<int, int>, string> comments;
        bool contradiction = false;
        
        for (int i = 0; i < m; i++) {
            int x, y;
            string role;
            cin >> x >> y >> role;
            
            if (contradiction) continue;
            
            int groupX = uf.find(x);
            int groupY = uf.find(y);
            
            if (groupX != groupY) {
                uf.unite(x, y);
            } else {
                if (comments.count({x, y}) && comments[{x, y}] != role) {
                    contradiction = true;
                }
            }
            
            comments[{x, y}] = role;
        }
        
        if (contradiction) {
            cout << -1 << endl;
        } else {
            int imposters = 0;
            for (int i = 1; i <= n; i++) {
                if (uf.parent[i] == i) {
                    int crewmates = uf.size[i];
                    imposters += max(crewmates, n - crewmates);
                }
            }
            cout << imposters << endl;
        }
    }
    
    return 0;
}