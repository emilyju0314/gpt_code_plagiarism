#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> lights;
vector<vector<int>> tree;
vector<int> subtree_light_count;
vector<int> subtree_rooms;
vector<int> depth;
int timer = 0;

void dfs(int node, int parent) {
    subtree_light_count[node] = lights[node];
    timer++;
    depth[node] = timer;

    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
            subtree_light_count[node] += subtree_light_count[child];
        }
    }

    timer++;
}

int main() {
    int n;
    cin >> n;

    lights.resize(n+1);
    tree.resize(n+1);
    subtree_light_count.resize(n+1);
    depth.resize(n+1);

    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> lights[i];
    }

    dfs(1, 0);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string task;
        int v;
        cin >> task >> v;

        if (task == "get") {
            cout << subtree_light_count[v] << endl;
        } else if (task == "pow") {
            lights[v] = 1 - lights[v];
            cout << subtree_light_count[v] << endl;
        }
    }

    return 0;
}