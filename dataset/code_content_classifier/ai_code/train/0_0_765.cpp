#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int V, d, N = 1001;

int f(int i) {
    if (i <= 0) return 1;
    int a = 1, b = 1;
    for (int j = 2; j <= i; j++) {
        int temp = b;
        b = (a + b) % N;
        a = temp;
    }
    return b;
}

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int v, set<int>& subset) {
    visited[v] = true;
    subset.insert(v);

    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(adj, visited, u, subset);
        }
    }
}

int main() {
    while (cin >> V >> d) {
        vector<int> F(V);
        for (int i = 0; i < V; i++) {
            F[i] = f(i + 1) % N;
        }

        vector<vector<int>> adj(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (abs(F[i] - F[j]) < d) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(V, false);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                set<int> subset;
                dfs(adj, visited, i, subset);
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}