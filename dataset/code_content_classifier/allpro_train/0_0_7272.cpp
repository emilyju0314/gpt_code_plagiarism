#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        parent[rootX] = rootY;
    }
};

int main() {
    srand(time(0));
    
    int n = 10;  // number of elements
    
    UnionFind uf(n);
    
    // random test
    for(int i = 0; i < n; i++) {
        int x = rand() % n;
        int y = rand() % n;
        cout << "Unite: " << x << " " << y << endl;
        uf.unite(x, y);
    }
    
    for(int i = 0; i < n; i++) {
        cout << "Parent of " << i << ": " << uf.find(i) << endl;
    }
    
    return 0;
}