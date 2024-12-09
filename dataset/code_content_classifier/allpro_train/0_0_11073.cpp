#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& parent, int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = find(parent, parent[x]);
    }
}

void unite(vector<int>& parent, int x, int y) {
    x = find(parent, x);
    y = find(parent, y);
    if (x != y) {
        parent[y] = x;
    }
}

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        
        if (n == 0 && m == 0) {
            break;
        }
        
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < m; i++) {
            int x, y, c;
            cin >> x >> y >> c;
            edges.push_back(make_pair(c, make_pair(x, y)));
        }
        
        sort(edges.begin(), edges.end());
        
        int total_cost = 0;
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        for (auto edge : edges) {
            int c = edge.first;
            int x = edge.second.first;
            int y = edge.second.second;
            
            if (find(parent, x) != find(parent, y)) {
                unite(parent, x, y);
            } else {
                total_cost += c;
            }
        }
        
        cout << total_cost << endl;
    }
    
    return 0;
}