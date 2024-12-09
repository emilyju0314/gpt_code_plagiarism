#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> parent;

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        parent[y] = x;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n+1);
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        unite(x, y);
    }

    unordered_map<int, int> component_sizes;
    for(int i = 1; i <= n; i++) {
        int parent_i = find(i);
        component_sizes[parent_i]++;
    }

    vector<int> sizes;
    for(auto it : component_sizes) {
        sizes.push_back(it.second);
    }

    sort(sizes.begin(), sizes.end());

    cout << sizes.size() << endl;
    for(int size : sizes) {
        cout << size << " ";
    }

    return 0;
}