#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> stamina(n);
    for(int i = 0; i < n; i++) {
        cin >> stamina[i];
    }
    
    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
    }
    
    int ans = 0;
    for(int i = 0; i < m; i++) {
        ans += min(stamina[edges[i].first-1], stamina[edges[i].second-1]);
    }
    
    cout << ans << endl;
    
    return 0;
}