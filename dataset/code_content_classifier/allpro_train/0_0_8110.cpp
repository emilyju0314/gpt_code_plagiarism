#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> capA(n-1), capB(n-1), flowAB(n, 0);

    // Input capacities of edges within part A and part B
    for(int i = 0; i < n-1; i++) {
        cin >> capA[i] >> capB[i];
    }

    // Input capacities of edges from A to B
    vector<vector<pair<int, int>>> edges(n);
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges[x-1].push_back({y-1, z});
    }

    // Calculate maximum flow value in the original network
    for(int i = 0; i < n-1; i++) {
        flowAB[i+1] = min({flowAB[i], capA[i]});
        for(auto edge : edges[i]) {
            flowAB[edge.first] = max({flowAB[edge.first], min({flowAB[i+1], edge.second})});
        }
    }

    int max_flow = flowAB[n-1];
    cout << max_flow << endl;

    // Process changes in the network
    for(int i = 0; i < q; i++) {
        int v, w;
        cin >> v >> w;
        v--;
        capA[v] = w;

        // Update the flow values
        for(int j = v; j < n-1; j++) {
            flowAB[j+1] = min({flowAB[j], capA[j]});
            for(auto edge : edges[j]) {
                flowAB[edge.first] = max({flowAB[edge.first], min({flowAB[j+1], edge.second})});
            }
        }

        // Print the maximum flow value after the change
        max_flow = flowAB[n-1];
        cout << max_flow << endl;
    }

    return 0;
}