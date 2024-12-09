#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        union_sets(x, y);
    }
    
    int connected_components = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            connected_components++;
        }
    }
    
    cout << connected_components - 1 << endl;
    
    return 0;
}