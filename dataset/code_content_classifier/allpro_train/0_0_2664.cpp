#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    // Constructing the graph
    vector<pair<int, int>> edges;
    int sum = (N * (N + 1)) / 2;
    for (int i = 1; i < N; i++) {
        edges.push_back({i, N});
    }

    // Output the graph
    cout << N - 1 << endl;
    for (auto edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}