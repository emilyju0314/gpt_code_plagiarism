#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;

vector<int> primes;

int multiply(int a, int b) {
    return (long long)a * b % MOD;
}

int inverse(int x) {
    long long result = 1;
    long long power = x;
    int MOD_MINUS_2 = MOD - 2;
    for (int i = 0; (1 << i) <= MOD_MINUS_2; i++) {
        if ((MOD_MINUS_2 & (1 << i)) != 0) {
            result = (result * power) % MOD;
        }
        power = (power * power) % MOD;
    }
    return result;
}

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& sizes, vector<int>& values) {
    sizes[node] = 1;
    int total = 1;
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, adj, sizes, values);
            sizes[node] += sizes[neighbor];
            total = multiply(total, values[neighbor]);
        }
    }
    values[node] = multiply(total, inverse(sizes[node]));
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n+1);
        vector<int> sizes(n+1);
        vector<int> values(n+1);

        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int m;
        cin >> m;

        primes.resize(m);
        for (int i = 0; i < m; i++) {
            cin >> primes[i];
        }

        // Calculate f(u, v) for each edge using DFS
        dfs(1, 0, adj, sizes, values);

        int result = 0;
        for (int i = 1; i <= n; i++) {
            result = (result + values[i]) % MOD;
        }

        cout << multiply(result, primes[m-1]) << endl;
    }

    return 0;
}