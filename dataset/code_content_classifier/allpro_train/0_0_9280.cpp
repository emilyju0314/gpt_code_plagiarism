#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;
std::vector<int> parent;
std::vector<int> decoration;
std::vector<std::vector<int>> adj_list;
std::vector<long long> factorial;

int find_parent(int u) {
    if (parent[u] != u) {
        parent[u] = find_parent(parent[u]);
    }
    return parent[u];
}

void union_sets(int u, int v) {
    int pu = find_parent(u);
    int pv = find_parent(v);
    if (pu != pv) {
        parent[pu] = pv;
    }
}

long long pow_mod(long long base, long long exp) {
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

void precompute_factorials(int n) {
    factorial.resize(n+1);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
}

int main() {
    int n;
    std::cin >> n;

    parent.resize(n+1);
    decoration.resize(n+1);
    adj_list.resize(n+1);

    precompute_factorials(n);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n-1; i++) {
        int u, v;
        std::cin >> u >> v;
        union_sets(u, v);
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        std::cin >> decoration[i];
    }

    for (int i = 1; i <= n; i++) {
        int p = find_parent(i);
        if (decoration[p] != 0 && decoration[p] != decoration[i]) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    long long result = 1;
    int num_components = 0;

    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            num_components++;
            int num_dec = 0;
            for (int j : adj_list[i]) {
                if (decoration[j] != 0) {
                    num_dec++;
                }
            }
            result = (result * factorial[num_dec]) % MOD;
        }
    }

    result = (result * factorial[num_components]) % MOD;
    result = (result * pow_mod(2, num_components-1)) % MOD;

    std::cout << result << std::endl;

    return 0;
}