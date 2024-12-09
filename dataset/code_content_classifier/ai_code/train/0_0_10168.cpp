#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> apples;
vector<vector<int>> tree;
vector<int> subtree_weight;
long long int total_apples_removed = 0;

void dfs(int node, int parent) {
    subtree_weight[node] = apples[node];
    for (int child : tree[node]) {
        if(child != parent) {
            dfs(child, node);
            subtree_weight[node] += subtree_weight[child];
        }
    }
}

void calculate_apples_removed(int node, int parent, int total_weight) {
    int max_weight = 0;
    for (int child : tree[node]) {
        if (child != parent) {
            max_weight = max(max_weight, subtree_weight[child]);
        }
    }
    
    int diff = total_weight - subtree_weight[node];
    if (diff > max_weight) {
        total_apples_removed += diff - max_weight;
    }
    
    for (int child : tree[node]) {
        if (child != parent) {
            calculate_apples_removed(child, node, total_weight);
        }
    }
}

int main() {
    int n;
    cin >> n;

    apples.resize(n);
    tree.resize(n);
    subtree_weight.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> apples[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(0, -1);
    calculate_apples_removed(0, -1, subtree_weight[0]);

    cout << total_apples_removed << endl;

    return 0;
}