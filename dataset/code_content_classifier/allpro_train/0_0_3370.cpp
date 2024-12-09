#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double calculateProbability(int N, vector<vector<int>>& graph, vector<bool>& removed, double P) {
    // Base case: If there are no edges left, return 1 if graph is connected, otherwise return 0
    bool connected = true;
    for (int i = 0; i < N; i++) {
        if (!removed[i]) {
            connected = false;
            break;
        }
    }
    if (connected) return 1.0;

    // Initialize probability
    double probability = 0.0;

    // Iterate through all edges
    for (int i = 0; i < N; i++) {
        if (!removed[i]) {
            removed[i] = true; // Remove edge i

            // Recursively calculate probability of remaining graph
            double edgeProbability = P / 100 * calculateProbability(N, graph, removed, P);

            // Update total probability
            probability += edgeProbability;

            removed[i] = false; // Restore edge i
        }
    }

    return probability;
}

int main() {
    int N, M, P;
    cin >> N >> M >> P;

    vector<vector<int>> graph(N);
    vector<bool> removed(M, false);

    // Read edges of the graph
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }

    // Calculate the probability of the remaining connected graph
    double result = calculateProbability(N, graph, removed, P);

    cout << fixed;
    cout.precision(12);
    cout << result << endl;

    return 0;
}