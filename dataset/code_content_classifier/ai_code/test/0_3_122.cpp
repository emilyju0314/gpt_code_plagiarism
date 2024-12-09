#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int v, int p, vector<int>& xor_vals, vector<vector<pair<int, int>>>& adj_list, vector<bool>& lights_set, vector<int>& xor_val) {
    xor_val[v] = xor_vals[v] ^ xor_vals[p];
    for (auto u : adj_list[v]) {
        if (u.first != p) {
            xor_vals[u.first] = xor_vals[v] ^ u.second;
            dfs(u.first, v, xor_vals, adj_list, lights_set, xor_val);
        }
    }
}

int count_ones(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

bool consistent_tree(vector<vector<pair<int, int>>>& adj_list, vector<vector<pair<int, int>>>& constraints, int n) {
    vector<bool> lights_set(n - 1, false);
    vector<int> xor_vals(n, 0);
    vector<int> xor_val(n);
    
    dfs(0, 0, xor_vals, adj_list, lights_set, xor_val);
    
    for (auto& edge : constraints) {
        int a = edge[0].first, b = edge[0].second, p = edge[1].second;
        int expectation = xor_val[a] ^ xor_val[b];
        int actual = xor_vals[a] ^ xor_vals[b];
        if (count_ones(expectation) % 2 != p) {
            return false;
        }
        if (!lights_set[a] && !lights_set[b]) {
            lights_set[a] = true;
            xor_vals[a] = actual ^ edge[1].first;
        } else if (!lights_set[b] && !lights_set[a]) {
            lights_set[b] = true;
            xor_vals[b] = actual ^ edge[1].first;
        } else if (actual != (xor_vals[a] ^ xor_vals[b])) {
            return false;
        }
    }
    
    cout << "YES" << endl;
    for (int i = 1; i < n; ++i) {
        cout << i << " " << adj_list[i][0].first << " " << adj_list[i][0].second << endl;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<pair<int, int>>> adj_list(n);
        for (int i = 0; i < n - 1; ++i) {
            int x, y, v;
            cin >> x >> y >> v;
            adj_list[x-1].push_back({y-1, v});
            adj_list[y-1].push_back({x-1, v});
        }
        
        vector<vector<pair<int, int>>> constraints(m);
        for (int i = 0; i < m; ++i) {
            int a, b, p;
            cin >> a >> b >> p;
            constraints[i].push_back({a-1, b-1});
            constraints[i].push_back({0, p});
        }
        
        if (!consistent_tree(adj_list, constraints, n)) {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}