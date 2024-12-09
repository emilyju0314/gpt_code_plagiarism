#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> subtreeSize;
int N;

void calculateSubtreeSize(int u, int p) {
    subtreeSize[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            calculateSubtreeSize(v, u);
            subtreeSize[u] += subtreeSize[v];
        }
    }
}

int countWaysToWin(int u, int p) {
    int ways = 0;
    for (int v : adj[u]) {
        if (v != p) {
            ways += countWaysToWin(v, u);
        }
    }
    ways += min(subtreeSize[u], N - subtreeSize[u]);
    return ways;
}

int main() {
    cin >> N;

    adj.resize(N + 1);
    subtreeSize.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        calculateSubtreeSize(i, 0);
    }

    int totalWays = 0;
    for (int i = 1; i <= N; i++) {
        totalWays += countWaysToWin(i, 0);
    }

    cout << totalWays << endl;

    return 0;
}