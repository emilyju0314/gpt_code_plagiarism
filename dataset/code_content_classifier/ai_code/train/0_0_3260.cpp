#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000009

using namespace std;

vector<int> parent, siz, ways, visited;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        if (siz[a] < siz[b]) swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
        ways[a] += ways[b];
        ways[a] %= MOD;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    siz.assign(n + 1, 1);
    ways.assign(n + 1, 0);
    visited.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        int total_ways = 0;

        if (find(a) != find(b)) {
            int ways_a = siz[find(a)];
            int ways_b = siz[find(b)];
            
            total_ways = (ways_a * ways_b) % MOD;
        }

        cout << total_ways << endl;

        unite(a, b);
    }

    return 0;
}