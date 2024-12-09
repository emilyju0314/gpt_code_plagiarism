#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n1, n2, m;
    cin >> n1 >> n2 >> m;

    vector<vector<int>> edges(m);
    // Read the edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    // Calculate the minimal degree of any vertex in graph G
    int minDegree = INT_MAX;
    vector<int> vertexDegree(n1 + n2 + 1, 0);

    for (auto edge : edges) {
        vertexDegree[edge[0]]++;
        vertexDegree[edge[1] + n1]++;
        int degree = max(vertexDegree[edge[0]], vertexDegree[edge[1] + n1]);
        minDegree = min(minDegree, degree);
    }

    // Find minimal k-covering for each k
    for (int k = 0; k < minDegree; k++) {
        // Initialize a set to keep track of covered vertices
        unordered_set<int> coveredVertices;

        // Initialize a vector to store the indices of edges in minimal k-covering
        vector<int> minimalEdges;

        // Iterate through all edges and add them to minimal k-covering if the incident vertices are not yet covered
        for (int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1] + n1;
            if (coveredVertices.find(u) == coveredVertices.end() && coveredVertices.find(v) == coveredVertices.end()) {
                minimalEdges.push_back(i + 1);
                coveredVertices.insert(u);
                coveredVertices.insert(v);
            }
        }

        // Output the minimal k-covering
        cout << minimalEdges.size() << " ";
        for (int edgeIndex : minimalEdges) {
            cout << edgeIndex << " ";
        }
        cout << endl;
    }

    return 0;
}