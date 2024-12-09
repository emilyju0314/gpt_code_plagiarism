#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> values(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }
    
    vector<int> buttonsToPress;
    for (int i = 1; i <= n; i++) {
        bool canPressButton = true;
        for (int neighbor : adj[i]) {
            if (values[neighbor] >= values[i]) {
                canPressButton = false;
                break;
            }
        }
        if (canPressButton) {
            buttonsToPress.push_back(i);
        }
    }

    if (buttonsToPress.empty()) {
        cout << -1 << endl;
    } else {
        cout << buttonsToPress.size() << endl;
        for (int button : buttonsToPress) {
            cout << button << " ";
        }
    }

    return 0;
}