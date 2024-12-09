#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_COLOR = 20;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }
};

int main() {
    int n;
    cin >> n;

    DSU dsu(1 << MAX_COLOR);

    vector<pair<int, int>> parts;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dsu.merge(a, b);
        parts.emplace_back(a, b);
    }

    vector<int> ans(2*n, -1);
    int highestBeauty = 0;
    for (int i = 0; i < n; i++) {
        int a = dsu.find(parts[i].first);
        int b = dsu.find(parts[i].second);

        highestBeauty = max(highestBeauty, __builtin_ctz(a ^ b));

        ans[2*i] = a;
        ans[2*i + 1] = b;
    }

    cout << highestBeauty << endl;

    for (int idx : ans) {
        cout << idx << " ";
    }
    
    return 0;
}