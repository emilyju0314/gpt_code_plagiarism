#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> subtree_size;

int dfs(int v, int p, int& close_pairs, int l, int w, map<int, int>& count, vector<long long>& total_weight) {
    int sum = 1;
    for (auto edge : adj[v]) {
        int u = edge.first;
        int weight = edge.second;
        if (u != p) {
            int subtree_sum = dfs(u, v, close_pairs, l, w, count, total_weight);
            sum += subtree_sum;
            total_weight.push_back(weight + total_weight.back());
            if (weight <= w) {
                close_pairs += count[l - 1 - total_weight.back()];
            }
            for (int i = 0; i <= l - 2 - total_weight.back(); i++) {
                close_pairs += count[i] * (count[i] - 1) / 2;
            }
            for (int i = 0; i < subtree_sum; i++) {
                count[total_weight[total_weight.size() - 2 - i]]++;
            }
        }
    }
    total_weight.pop_back();
    count[0]++;
    return sum;
}

int main() {
    int n, l, w;
    cin >> n >> l >> w;

    adj.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int p, weight;
        cin >> p >> weight;
        adj[i+1].push_back({p, weight});
        adj[p].push_back({i+1, weight});
    }

    subtree_size.resize(n + 1);
    vector<long long> total_weight;
    map<int, int> count;
    int close_pairs = 0;
    
    dfs(1, 0, close_pairs, l, w, count, total_weight);

    cout << close_pairs << endl;

    return 0;
}