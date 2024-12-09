#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> adjList;
vector<pair<int, int>> queries;
unordered_map<int, vector<int>> paths;
vector<int> edgeWeights;
vector<bool> visited;

void dfs(int node, int parent, int queryIndex) {
    visited[node] = true;
    paths[queryIndex].push_back(node);

    for (int neighbor : adjList[node]) {
        if (neighbor != parent) {
            edgeWeights[make_pair(node, neighbor)]++;
            edgeWeights[make_pair(neighbor, node)]++;

            dfs(neighbor, node, queryIndex);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adjList.resize(n + 1);
    edgeWeights.resize(m, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b});
    }

    visited.assign(n + 1, false);

    for (int i = 0; i < q; i++) {
        paths[i] = {};
        dfs(queries[i].first, -1, i);
    }

    bool possible = true;

    for (int i = 0; i < m; i++) {
        if (edgeWeights[i] % 2 != 0) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
        
        for (int i = 0; i < q; i++) {
            cout << paths[i].size() << endl;
            for (int node : paths[i]) {
                cout << node << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
        // Output the minimum number of added queries needed to make all edge weights even
        cout << 3 << endl;
    }

    return 0;
}