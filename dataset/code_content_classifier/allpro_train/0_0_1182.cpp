#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<pair<int, char>>> tree;
vector<int> res;

pair<int, int> dfs(int v, int parent) {
    vector<int> depths;
    for (auto u : tree[v]) {
        if (u.first != parent) {
            depths.push_back(dfs(u.first, v).first + (u.second == tree[v][0].second));
        }
    }
    int mx1 = 0, mx2 = 0;
    for (int d : depths) {
        if (d >= mx1) {
            mx2 = mx1;
            mx1 = d;
        } else if (d > mx2) {
            mx2 = d;
        }
    }
    res[v] = mx1 + mx2;
    return {mx1, mx2};
}

int main() {
    int n;
    cin >> n;
    
    tree.resize(n);
    res.resize(n);
    
    for (int i = 1; i < n; i++) {
        int p;
        char c;
        cin >> p >> c;
        tree[p - 1].push_back({i, c});
    }
    
    dfs(0, -1);
    
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    
    return 0;
}