#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> graph;
vector<unordered_set<int>> queries;
vector<int> edgeWeights;

bool dfs(int node, int target, vector<int>& path) {
    path.push_back(node);
    if (node == target) {
        return true;
    }
    for (int neighbor : graph[node]) {
        if (find(path.begin(), path.end(), neighbor) == path.end()) {
            if (dfs(neighbor, target, path)) {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    edgeWeights.assign(m, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int q;
    cin >> q;

    queries.resize(q);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries[i] = {a, b};
    }

    for (int i = 0; i < q; i++) {
        int a = queries[i][0];
        int b = queries[i][1];

        vector<int> path;
        if (dfs(a, b, path)) {
            for (int j = 0; j < path.size() - 1; j++) {
                edgeWeights[path[j] * n + path[j + 1] - 1]++;
            }
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < q; i++) {
        int a = queries[i][0];
        int b = queries[i][1];

        vector<int> path;
        dfs(a, b, path);
        cout << path.size() << endl;
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}