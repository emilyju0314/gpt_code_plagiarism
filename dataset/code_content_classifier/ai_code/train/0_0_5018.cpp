#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, vector<int>> adj_list;

void dfs(int u, int parent, vector<int>& sub_tree) {
    sub_tree.push_back(u);
    for (int v : adj_list[u]) {
        if (v != parent) {
            dfs(v, u, sub_tree);
        }
    }
}

bool isomorphic(vector<int>& tree1, vector<int>& tree2) {
    if (tree1.size() != tree2.size()) return false;

    unordered_map<int, int> mapping;
    for (int i = 0; i < tree1.size(); i++) {
        if (mapping.find(tree1[i]) == mapping.end()) {
            mapping[tree1[i]] = tree2[i];
        } else {
            if (mapping[tree1[i]] != tree2[i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n1, m1, n2;
    cin >> n1 >> m1;
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<vector<int>> tree1;
    unordered_set<int> visited;
    for (int i = 1; i <= n1; i++) {
        if (visited.find(i) == visited.end()) {
            vector<int> sub_tree;
            dfs(i, -1, sub_tree);
            tree1.push_back(sub_tree);
        }
    }

    cin >> n2;
    vector<pair<int, int>> edges2;
    for (int i = 0; i < n2 - 1; i++) {
        int w, x;
        cin >> w >> x;
        edges2.emplace_back(w, x);
    }
    
    int count = 0;
    for (vector<int>& sub_tree : tree1) {
        for (int i = 0; i < n2; i++) {
            if (isomorphic(sub_tree, {edges2[i].first, edges2[i].second})) {
                count++;
                break;
            }
        }
    }

    cout << count << endl;

    return 0;
}