#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 500005;

int parent[MAXN];
int size[MAXN];
long long values[MAXN];

int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        values[a] += values[b];
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        for (int j = 1; j <= n; j++) {
            parent[j] = j;
            size[j] = 1;
            cin >> values[j];
        }

        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        }

        vector<long long> factors;
        for (int j = 1; j <= n; j++) {
            if (parent[j] == j) {
                factors.push_back(values[j]);
            }
        }

        long long gcd = factors[0];
        for (int j = 1; j < factors.size(); j++) {
            gcd = __gcd(gcd, factors[j]);
        }

        cout << gcd << endl;
    }

    return 0;
}