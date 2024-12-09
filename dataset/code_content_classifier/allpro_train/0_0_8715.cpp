#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isCyclicUtil(vector<vector<int>>& graph, vector<int>& inDegree) {
    int n = graph.size();
    vector<int> visited(n);
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            visited[i] = 1;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
                visited[v] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return true;
        }
    }

    return false;
}

bool canMakeAcyclic(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> inDegree(n);

    for (int i = 0; i < n; i++) {
        for (int v : graph[i]) {
            inDegree[v]++;
        }
    }
    
    if (isCyclicUtil(graph, inDegree)) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int v = graph[i][j];
            inDegree[v]--;
            if (isCyclicUtil(graph, inDegree)) {
                return true;
            }
            inDegree[v]++;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u-1].push_back(v-1);
    }

    if (canMakeAcyclic(graph)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}