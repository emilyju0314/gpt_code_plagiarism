#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m, k;
vector<vector<int>> adj_list;
set<pair<int, int>> forbidden_pairs;

bool dfs(int u, int parent) {
    for (int v : adj_list[u]) {
        if (v == parent) continue;
        if (forbidden_pairs.count({u, v}) || forbidden_pairs.count({v, u})) {
            return false;
        }
        if (!dfs(v, u)) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m >> k;
    
    adj_list.resize(n+1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
        forbidden_pairs.insert({a, b});
        forbidden_pairs.insert({b, a});
    }
    
    if ((int)adj_list[1].size() > k) {
        cout << "impossible" << endl;
    } else if (dfs(1, 0)) {
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }
    
    return 0;
}