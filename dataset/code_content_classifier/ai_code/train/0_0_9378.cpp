#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool dfs(int node, int target, vector<vector<pair<int, char>>> &adjList, vector<int> &visited, map<pair<int,int>, char> &edgeLabels, vector<int> &path) {
    visited[node] = 1;
    path.push_back(node);

    if (node == target) {
        return true;
    }

    for (auto neighbor : adjList[node]) {
        int nextNode = neighbor.first;
        if (visited[nextNode] == 0) {
            if (dfs(nextNode, target, adjList, visited, edgeLabels, path)) {
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

    vector<vector<pair<int, char>>> adjList(n);
    map<pair<int,int>, char> edgeLabels;

    for (int i = 0; i < m; i++) {
        char type;
        int u, v, k;
        string label;

        cin >> type;

        if (type == '+') {
            cin >> u >> v >> label;
            adjList[u-1].push_back({v-1, label[0]});
            edgeLabels[{u-1, v-1}] = label[0];
        } else if (type == '-') {
            cin >> u >> v;
            for (auto it = adjList[u-1].begin(); it != adjList[u-1].end(); ) {
                if (it->first == v-1) {
                    it = adjList[u-1].erase(it);
                } else {
                    it++;
                }
            }
            edgeLabels.erase({u-1, v-1});
        } else {
            cin >> k;
            vector<int> visited(n, 0);
            vector<int> path;

            if (dfs(0, 0, adjList, visited, edgeLabels, path) && path.size() >= k) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}