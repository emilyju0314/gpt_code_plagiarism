#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int find(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}

void unionSet(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    
    if (rootX == rootY) return;
    
    if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> parent(n);
    vector<int> rank(n, 0);
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    unordered_map<int, int> rabbits;
    
    for (int i = 0; i < k; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        
        if (type == 1) {
            unionSet(parent, rank, u, v);
        } else if (type == 2) {
            // Do nothing
        } else if (type == 3) {
            if (find(parent, u) == find(parent, v)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    
    return 0;
}