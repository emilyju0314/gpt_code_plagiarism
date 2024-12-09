#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> adj_list;
vector<pair<int, int>> paths;
unordered_map<int, int> counter;

void dfs(int node, int parent) {
    counter[node] = 1;
    for (int neighbor : adj_list[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node);
            counter[node] += counter[neighbor];
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj_list.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        paths.push_back({u, v});
    }

    dfs(1, 0);

    long long result = 0;
    for (const pair<int, int>& path : paths) {
        int u = path.first, v = path.second;
        int a = (counter[u] < counter[v]) ? u : v;
        int b = (counter[u] < counter[v]) ? v : u;
        result += (counter[a] - 1) * (counter[b] - 1);
    }

    cout << result << endl;

    return 0;
}