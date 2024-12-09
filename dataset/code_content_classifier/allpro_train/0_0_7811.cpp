#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        graph[v-1][u-1] = graph[u-1][v-1] = w; // Undirected graph
    }

    vector<vector<long long>> dp(q+1, vector<long long>(n, 0));
    
    for (int i = 1; i <= q; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = dp[i-1][j]; // Initialize with the previous path weights
            // Find the maximum weight path of length i that ends at vertex j
            for (int k = 0; k < n; k++) {
                if (graph[j][k] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + graph[j][k]);
                }
            }
        }
    }

    long long sum = 0;
    for (int i = 1; i <= q; i++) {
        for (int j = 0; j < n; j++) {
            sum = (sum + dp[i][j]) % MOD; // Calculate the sum of weights of the paths
        }
    }

    cout << sum << endl;

    return 0;
}