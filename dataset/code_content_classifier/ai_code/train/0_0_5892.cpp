#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> adj;
vector<int> luckyEdges;
map<int, int> subtreeLuckyEdges, subtreeEdges;

void dfs(int node, int parent) {
    subtreeLuckyEdges[node] = luckyEdges[node];
    subtreeEdges[node] = 1;
    
    for(int nei : adj[node]) {
        if(nei != parent) {
            dfs(nei, node);
            subtreeLuckyEdges[node] += subtreeLuckyEdges[nei];
            subtreeEdges[node] += subtreeEdges[nei];
        }
    }
}

long long countTriples(int n) {
    long long totalTriples = 0;
    
    for(int i = 0; i < n; i++) {
        totalTriples += (long long) subtreeLuckyEdges[i] * (n - subtreeEdges[i]);
        totalTriples += (long long) (subtreeEdges[i] - subtreeLuckyEdges[i]) * subtreeLuckyEdges[i];
        totalTriples += (long long) subtreeLuckyEdges[i] * (subtreeLuckyEdges[i] - 1);
    }
    
    return totalTriples;
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n);
    luckyEdges.resize(n);
    
    for(int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
        
        if(w == 4 || w == 7) {
            luckyEdges[u]++;
            luckyEdges[v]++;
        }
    }
    
    dfs(0, -1);
    
    long long answer = countTriples(n);
    
    cout << answer << endl;
    
    return 0;
}