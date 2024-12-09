#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, int p, vector<vector<int>>& tree, vector<int>& b, vector<int>& w, vector<int>& count_b, vector<int>& count_w) {
    count_b[u] = b[u];
    count_w[u] = w[u];
    
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs(v, u, tree, b, w, count_b, count_w);
        count_b[u] += count_b[v];
        count_w[u] += count_w[v];
    }  
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> b(n);
        vector<int> w(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }
        
        vector<vector<int>> tree(n);
        for (int i = 0; i < n-1; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        
        vector<int> count_b(n);
        vector<int> count_w(n);
        dfs(0, -1, tree, b, w, count_b, count_w);
        
        int max_villages = min(n, m);
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            int votes_b = count_b[i];
            int votes_w = count_w[i];
            int diff = votes_w - votes_b;
            if (diff >= 0) {
                res++;
            }
        }
        
        cout << min(max_villages, res) - 1 << endl;
    }
    
    return 0;
}