#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<pair<int, int>>> adj;
vector<int> outDegrees;
int result = 0;

void generateTuples(vector<int>& tuple, int idx) {
    if (idx == k) {
        // Check if the tuple is valid
        for (int i = 0; i < n; i++) {
            int u = i;
            for (int j = 0; j < outDegrees[u]; j++) {
                int minWeight = INT_MAX;
                int count = 0;
                for (int v = 0; v < outDegrees[u]; v++) {
                    int edgeWeight = adj[u][v].second;
                    if (edgeWeight < minWeight) {
                        minWeight = edgeWeight;
                        count++;
                    }
                    if (count == tuple[j]) {
                        u = adj[u][v].first;
                        break;
                    }
                }
                if (u == i) {
                    break;
                }
            }
            if (u != i) {
                return;
            }
        }
        result++;
        return;
    }

    for (int i = 1; i <= idx + 1; i++) {
        tuple[idx] = i;
        generateTuples(tuple, idx + 1);
    }
}

int main() {
    cin >> n >> m >> k;
    
    adj.resize(n);
    outDegrees.assign(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        adj[u].push_back({v, w});
        outDegrees[u]++;
    }

    vector<int> tuple(k);
    generateTuples(tuple, 0);

    cout << result << endl;

    return 0;
}