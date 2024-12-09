#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define MOD 1000000007

using namespace std;

vector<int> parent;
vector<long long> weights;
vector<long long> depths;
map<int, vector<pair<int, long long>>> edges;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unionSets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
        weights[x] = (weights[x] + weights[y]) % MOD;
    }
}

int main() {
    int n;
    cin >> n;

    parent.resize(n + 1);
    weights.resize(n + 1);
    depths.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int v, x;
            cin >> v >> x;
            int root_v = find(v);
            unionSets(root_v, i);
            edges[root_v].push_back({i, depths[v] + x});
        }
    }

    long long result = 0;
    for (int i = 1; i <= n; i++) {
        result = (result + weights[find(i)]) % MOD;
        for (auto& p : edges[i]) {
            depths[p.first] = p.second;
        }
    }

    cout << result << endl;

    return 0;
}