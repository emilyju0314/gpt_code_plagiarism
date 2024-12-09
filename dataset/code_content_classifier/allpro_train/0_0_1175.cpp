#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n+1);
    vector<int> deg(n+1, 0);
    
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            ans++;
        }
    }
    
    cout << (ans + 1) / 2 << endl;
    
    return 0;
}