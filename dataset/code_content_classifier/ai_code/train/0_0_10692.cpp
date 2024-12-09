#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    parent[find(u)] = find(v);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    parent.resize(n+1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            components++;
        }
    }
    
    int leaves = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            int edges = 0;
            for (int j = 1; j <= n; j++) {
                if (find(j) == i) {
                    edges++;
                }
            }
            if (edges == 1) {
                leaves++;
            }
        }
    }
    
    int result = components - leaves - 1;
    cout << result << endl;
    
    return 0;
}