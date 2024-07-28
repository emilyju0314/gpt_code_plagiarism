#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& s) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, graph, visited, s);
        }
    }
    s.push(node);
}

void reverseDFS(int node, vector<vector<int>>& reverseGraph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : reverseGraph[node]) {
        if (!visited[neighbor]) {
            reverseDFS(neighbor, reverseGraph, visited);
        }
    }
}

int findSCCs(vector<vector<int>>& graph, vector<vector<int>>& reverseGraph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, graph, visited, s);
        }
    }

    fill(visited.begin(), visited.end(), false);
    int SCCs = 0;

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        if (!visited[node]) {
            reverseDFS(node, reverseGraph, visited);
            SCCs++;
        }
    }

    return SCCs;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        // 初始化有向圖和反向圖
        vector<vector<int>> graph(n);
        vector<vector<int>> reverseGraph(n);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            reverseGraph[v].push_back(u);
        }

        // 找出最大強聯通分量的數量
        int SCCs = findSCCs(graph, reverseGraph);

        cout << SCCs << endl;
    }

    return 0;
}
