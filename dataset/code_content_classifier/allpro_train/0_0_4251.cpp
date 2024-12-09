#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<vector<int>> children;
vector<int> sum;
vector<int> a;

int dfs(int v) {
    if (a[v] != -1) return a[v];
    int min_child_sum = INT_MAX;
    for (int u : children[v]) {
        int child_sum = dfs(u);
        min_child_sum = min(min_child_sum, child_sum);
    }
    if (sum[v] == -1) {
        a[v] = min_child_sum;
    } else {
        a[v] = sum[v] - (children[v].size() * sum[v]);
    }
    return a[v];
}

int main() {
    int n;
    cin >> n;

    parent.resize(n);
    children.resize(n);
    sum.resize(n);
    a.resize(n, -1);

    for (int i = 1; i < n; i++) {
        cin >> parent[i];
        parent[i]--;
        children[parent[i]].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        cin >> sum[i];
    }

    int total_sum = dfs(0);
    if (total_sum < 0) {
        cout << -1 << endl;
    } else {
        cout << total_sum << endl;
    }

    return 0;
}