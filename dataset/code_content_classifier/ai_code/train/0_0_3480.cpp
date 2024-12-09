#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<vector<int>> tree;
vector<int> parent;
vector<unordered_set<int>> distOne;

void bfs(int root) {
    queue<int> q;
    q.push(root);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int child : tree[curr]) {
            if (child != parent[curr]) {
                parent[child] = curr;
                distOne[curr].insert(child);
                q.push(child);
            }
        }
    }
}

bool checkPath(int u, vector<int>& vertices) {
    if (u == 1) return true;
    for (int vertex : vertices) {
        if (distOne[u].find(vertex) != distOne[u].end()) {
            if (checkPath(parent[u], vertices)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    tree.resize(n + 1);
    parent.resize(n + 1);
    distOne.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    bfs(1);

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> vertices(k);
        for (int j = 0; j < k; j++) {
            cin >> vertices[j];
        }

        if (checkPath(vertices.front(), vertices)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}