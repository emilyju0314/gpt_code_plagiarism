#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

class Vertex {
public:
    int x, y;
    Vertex(int x, int y) : x(x), y(y) {}
};

class Edge {
public:
    int start, end;
    Edge(int start, int end) : start(start), end(end) {}
};

class WarpGate {
public:
    int source, destination;
    WarpGate(int source, int destination) : source(source), destination(destination) {}
};

void findShortestPath(vector<vector<Vertex>> maps, vector<vector<Edge>> mapEdges, vector<vector<WarpGate>> warpGates, int sl, int dl, int sn, int dn) {
    // Implement Dijkstra's algorithm to find the shortest path
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int numMaps;
        cin >> numMaps;

        vector<vector<Vertex>> maps(numMaps);
        vector<vector<Edge>> mapEdges(numMaps);
        vector<vector<WarpGate>> warpGates(numMaps);

        // Read the input datasets and create objects for vertices, edges, and warp gates 

        int sl, dl, sn, dn;
        cin >> sl >> dl >> sn >> dn;

        findShortestPath(maps, mapEdges, warpGates, sl, dl, sn, dn);
    }

    return 0;
}