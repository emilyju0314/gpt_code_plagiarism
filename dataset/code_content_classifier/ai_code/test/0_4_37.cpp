#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> parent;

int find(int node) {
    if(parent[node] == node) {
        return node;
    }
    return parent[node] = find(parent[node]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if(u != v) {
        parent[u] = v;
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        parent.resize(n+1);
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        vector<pair<int, pair<int, int>>> restrictions;
        for(int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            restrictions.push_back({a, {b, c}});
        }

        vector<pair<int, int>> edges;
        for(int i = 2; i <= n; i++) {
            edges.push_back({1, i});
        }

        queue<int> q;
        for(int i = 0; i < m; i++) {
            int a = restrictions[i].first;
            int b = restrictions[i].second.first;
            int c = restrictions[i].second.second;

            if(find(b) != find(c)) {
                unite(a, b);
                q.push(i);
                edges.push_back({b, c});
            }
        }

        while(!q.empty()) {
            int i = q.front();
            q.pop();
            int a = restrictions[i].first;
            int b = restrictions[i].second.first;
            int c = restrictions[i].second.second;

            if(find(b) != find(c)) {
                unite(b, c);
                edges.push_back({b, c});
            }
        }

        for(auto edge : edges) {
            cout << edge.first << " " << edge.second << endl;
        }
    }

    return 0;
}