#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long modpow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> keys(n);
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    vector<vector<int>> adjList(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    long long result = 0;
    long long total_pairs = modpow(2, n);
    for (int x = 0; x < (1 << k); x++) {
        bool valid = true;
        for (int i = 0; i < n; i++) {
            for (int neighbor : adjList[i]) {
                if ((keys[i] ^ x) == keys[neighbor]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        if (valid) {
            long long num_pairs = modpow(2, __builtin_popcount(x));
            result = (result + num_pairs) % MOD;
        }
    }

    result = (result * modpow(total_pairs, MOD - 2)) % MOD;
    cout << result << endl;

    return 0;
}