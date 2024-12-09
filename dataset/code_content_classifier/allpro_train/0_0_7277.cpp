#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 5;

int n, q;
vector<int> adj[maxn];
vector<int> p(maxn), pos(maxn), val(maxn);

void dfs(int u, int& timer) {
    pos[u] = timer++;
    val[pos[u]] = p[u];
    for (int v : adj[u]) {
        dfs(v, timer);
    }
}

int main() {
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        adj[u - 1].push_back(i - 1);
    }
    
    int timer = 0;
    dfs(0, timer);
    
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        cnt[val[i]] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
    }
    
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            swap(val[pos[x]], val[pos[y]]);
        } else {
            int ans = 0, mex = 0;
            while (ans < n) {
                if (cnt[ans] == ans) {
                    mex = ans;
                    ans++;
                } else {
                    break;
                }
            }
            cout << mex + 1 << endl;
        }
    }
    
    return 0;
}