#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> parent;

int find(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find(parent[v]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[a] = b;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n+1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        unite(u, v);
    }

    unordered_set<int> cycles;

    for (int i = 1; i <= n; i++) {
        int p = find(i);
        cycles.insert(p);
    }

    int count = 0;
    for (int cycle : cycles) {
        if (cycle == parent[cycle]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}