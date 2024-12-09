#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v;
    long long cost;
};

int find(int x, vector<int>& parent) {
    if (x != parent[x]) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void merge(int x, int y, vector<int>& parent, vector<int>& rank) {
    x = find(x, parent);
    y = find(y, parent);
    if (x != y) {
        if (rank[x] < rank[y]) {
            swap(x, y);
        }
        parent[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<Edge> offers(m);
    for (int i = 0; i < m; i++) {
        cin >> offers[i].u >> offers[i].v >> offers[i].cost;
        offers[i].u--;
        offers[i].v--;
    }
    
    sort(offers.begin(), offers.end(), [](Edge a, Edge b) {
        return a.cost < b.cost;
    });
    
    long long total_cost = 0;
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        if (find(offers[i].u, parent) != find(offers[i].v, parent)) {
            total_cost += offers[i].cost;
            merge(offers[i].u, offers[i].v, parent, rank);
        }
    }
    
    for (int i = 0; i < n; i++) {
        long long min_cost = a[i];
        for (int j = 0; j < n; j++) {
            if (find(i, parent) != find(j, parent)) {
                min_cost = min(min_cost, a[j] + a[i]);
            }
        }
        total_cost += min_cost;
    }
    
    cout << total_cost << "\n";
    
    return 0;
}