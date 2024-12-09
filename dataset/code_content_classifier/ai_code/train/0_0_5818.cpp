#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, pair<int, int>>>> adj;
vector<long long> weights;

void dfs(int node, long long current_weight) {
    if(adj[node].size() == 1 && node != 1) {
        weights.push_back(current_weight);
        return;
    }

    for(auto edge : adj[node]) {
        int child = edge.first;
        int weight = edge.second.first;
        int cost = edge.second.second;

        dfs(child, current_weight + weight);
    }
}

bool is_possible(long long target, int coins) {
    long long total_cost = 0;
    for (long long weight : weights) {
        if (target < weight) {
            total_cost += (weight - target) * coins;
        }
    }
    return total_cost <= (long long)coins * target;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        long long S;
        cin >> n >> S;

        adj.clear();
        adj.resize(n + 1);
        weights.clear();

        for(int i = 1; i < n; i++) {
            int u, v, w, c;
            cin >> u >> v >> w >> c;
            adj[u].push_back({v, {w, c}});
            adj[v].push_back({u, {w, c}});
        }

        dfs(1, 0);

        long long low = 0, high = (1e15);
        while(low < high) {
            long long mid = low + (high - low) / 2;
            if(is_possible(mid, 2)) {
               high = mid;
            } else {
               low = mid + 1;
            }
        }

        cout << low << endl;
    }

    return 0;
}