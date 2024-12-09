#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree[200005];
bool visited[200005];
int subtree_size[200005];

int dfs(int node, int parent) {
    subtree_size[node] = 1;
    for(int child : tree[node]) {
        if(child != parent) {
            subtree_size[node] += dfs(child, node);
        }
    }
    return subtree_size[node];
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, -1);

    vector<pair<int, pair<int, int>>> transformations;

    for(int i = 1; i <= n; i++) {
        for(int child : tree[i]) {
            if(subtree_size[child] < subtree_size[i]) {
                transformations.push_back({i, {child, child}});
            }
        }
    }

    cout << transformations.size() << endl;
    for(auto transformation : transformations) {
        cout << transformation.first << " " << transformation.second.first << " " << transformation.second.second << endl;
    }

    return 0;
}