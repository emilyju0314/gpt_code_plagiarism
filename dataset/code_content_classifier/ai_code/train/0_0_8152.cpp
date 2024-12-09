#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

vector<long long> beauty;
vector<vector<int>> adj_list;
vector<long long> subtree_sum;
vector<long long> multiplier;
vector<int> subtree_size;

int dfs(int node, int parent) {
    subtree_size[node] = 1;
    for (int child : adj_list[node]) {
        if (child != parent) {
            subtree_size[node] += dfs(child, node);
            subtree_sum[node] += (subtree_sum[child] + multiplier[node] * beauty[child]) % MOD;
        }
    }
    return subtree_size[node];
}

int main() {
    int n;
    cin >> n;

    beauty.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> beauty[i];
    }

    adj_list.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; // 0-indexed
        b--;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    subtree_sum.assign(n, 0);
    multiplier.assign(n, 0);
    subtree_size.assign(n, 0);
    multiplier[0] = 1;

    dfs(0, -1);

    long long result = 0;
    for (int i = 0; i < n; i++) {
        result = (result + subtree_sum[i]) % MOD;
    }

    cout << result << endl;

    return 0;
}