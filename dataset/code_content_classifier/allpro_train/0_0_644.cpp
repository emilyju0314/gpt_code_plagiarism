#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAXN = 2e5 + 5;

int n;
vector<int> w(MAXN);
vector<vector<pair<int, int>>> tree(MAXN);
double ans = 0.0;

void dfs(int u, int parent, int dist) {
    for (auto p : tree[u]) {
        int v = p.first;
        int w_uv = p.second;
        if (v != parent) {
            dfs(v, u, w_uv);
            ans += 2.0 * min(w[v], n - w[v]) * w_uv;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        tree[a].push_back({b, l});
        tree[b].push_back({a, l});
    }
    
    dfs(1, -1, 0);
    
    cout << fixed << setprecision(10) << "1 " << ans / n << endl;
    
    return 0;
}