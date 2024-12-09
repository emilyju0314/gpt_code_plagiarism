#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<pair<int, int>>> adj;
int n, m;
int result = 0;

int modpow(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void dfs(int node, int parent, int value, unordered_map<int, int>& freq) {
    value = (10*value + adj[parent][node].second) % m;
    freq[value]++;
    
    for (auto neighbor : adj[node]) {
        if (neighbor.first != parent) {
            dfs(neighbor.first, node, value, freq);
        }
    }
}

void count_interesting_pairs(int node, int parent, int value, unordered_map<int, int>& freq) {
    value = (10*value + adj[parent][node].second) % m;
    freq[value]--;

    result += freq[value];
    
    for (auto neighbor : adj[node]) {
        if (neighbor.first != parent) {
            count_interesting_pairs(neighbor.first, node, value, freq);
        }
    }
}

int main() {
    cin >> n >> m;
    
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    unordered_map<int, int> freq;
    freq[0] = 1;
    
    for (int i = 0; i < adj[0].size(); i++) {
        dfs(adj[0][i].first, 0, adj[0][i].second, freq);
    }
    
    for (int i = 0; i < adj[0].size(); i++) {
        count_interesting_pairs(adj[0][i].first, 0, adj[0][i].second, freq);
    }
    
    cout << result << endl;
    
    return 0;
}