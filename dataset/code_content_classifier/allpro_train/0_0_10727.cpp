#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int destination;
    int distance;
};

struct Graph {
    vector<vector<Edge>> adjList;
};

void DFS(Graph& graph, int current, int length, vector<int>& visited, int& maxLength, vector<int>& currentPath, vector<int>& longestPath) {
    visited[current] = 1;
    currentPath.push_back(current);

    if (length > maxLength) {
        maxLength = length;
        longestPath = currentPath;
    }

    for (const Edge& edge : graph.adjList[current]) {
        if (visited[edge.destination] == 0) {
            DFS(graph, edge.destination, length + edge.distance, visited, maxLength, currentPath, longestPath);
        }
    }

    visited[current] = 0;
    currentPath.pop_back();
}

int main() {
    int ns, nl;
    while (cin >> ns >> nl && (ns != 0 || nl != 0)) {
        Graph graph;
        graph.adjList.resize(ns + 1);

        for (int i = 0; i < nl; i++) {
            int source, destination, distance;
            cin >> source >> destination >> distance;

            graph.adjList[source].push_back({destination, distance});
            graph.adjList[destination].push_back({source, distance});
        }

        int maxLength = 0;
        vector<int> visited(ns + 1, 0);
        vector<int> currentPath, longestPath;

        for (int i = 1; i <= ns; i++) {
            DFS(graph, i, 0, visited, maxLength, currentPath, longestPath);
        }

        cout << maxLength << endl;
        for (int station : longestPath) {
            cout << station << " ";
        }
        cout << endl;
    }

    return 0;
}