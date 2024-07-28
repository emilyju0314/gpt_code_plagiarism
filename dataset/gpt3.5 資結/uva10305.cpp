#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologicalSort(vector<vector<int>>& graph, vector<int>& indegree) {
    vector<int> result;
    queue<int> q;

    for (int i = 1; i < indegree.size(); i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int numNodes, numEdges;

    while (cin >> numNodes >> numEdges) {
        if (numNodes == 0 && numEdges == 0) {
            break;
        }

        vector<vector<int>> graph(numNodes + 1);
        vector<int> indegree(numNodes + 1, 0);

        for (int i = 0; i < numEdges; i++) {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            indegree[to]++;
        }

        topologicalSort(graph, indegree);
    }

    return 0;
}