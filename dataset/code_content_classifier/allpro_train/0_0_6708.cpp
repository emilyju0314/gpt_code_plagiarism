#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> efficiency;

int dfs(int node) {
    int sum = 0;
    int count = 0;

    for (auto neighbor : adj[node]) {
        int next_node = neighbor.first;
        int next_efficiency = neighbor.second;

        int subordinates_efficiency = dfs(next_node);

        if (subordinates_efficiency % 2 == 0) {
            count++;
            sum += subordinates_efficiency;
        }
    }

    if (count % 2 == 0) {
        sum += efficiency[node];
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    efficiency.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        int p, a;
        cin >> p >> a;
        adj[p].push_back({i, a});
        efficiency[i] = a;
    }

    int max_efficiency = dfs(1);
    cout << max_efficiency << endl;

    return 0;
}