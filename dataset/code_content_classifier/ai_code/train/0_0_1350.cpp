#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000;

vector<int> primes;

void sieve() {
    vector<bool> is_prime(MAX_M + 1, true);

    for (int p = 2; p <= MAX_M; p++) {
        if (is_prime[p]) {
            primes.push_back(p);

            for (int i = p * 2; i <= MAX_M; i += p) {
                is_prime[i] = false;
            }
        }
    }
}

void dfs(int node, vector<vector<int>>& adj_list, vector<int>& values, vector<int>& subtree_values, vector<int>& count_primes, int m) {
    subtree_values[node] = values[node];

    for (int next_node : adj_list[node]) {
        if (next_node != node) {
            dfs(next_node, adj_list, values, subtree_values, count_primes, m);
            subtree_values[node] += subtree_values[next_node];
        }
    }

    for (int prime : primes) {
        for (int k = 0; ; k++) {
            int target_value = prime + m * k;
            if (target_value > subtree_values[node]) {
                break;
            }

            count_primes[target_value]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> values(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    sieve();

    vector<vector<int>> adj_list(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int q;
    cin >> q;

    vector<int> subtree_values(n + 1, 0);
    vector<int> count_primes(MAX_N + 1, 0);

    dfs(1, adj_list, values, subtree_values, count_primes, m);

    for (int i = 0; i < q; i++) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            int v, x;
            cin >> v >> x;
            
            values[v] += x;
            for (int j = 1; j <= n; j++) {
                count_primes[j] = 0;
            }

            dfs(1, adj_list, values, subtree_values, count_primes, m);
        } else {
            int v;
            cin >> v;
            cout << count_primes[v] << endl;
        }
    }

    return 0;
}