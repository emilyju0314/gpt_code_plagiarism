#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n+1);
    vector<int> parent(n+1);
    vector<int> degree(n+1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> parent[i];
        if (parent[i] != 0) {
            adj[parent[i]].push_back(i);
            degree[parent[i]]++;
        }
    }
    
    queue<int> q;
    
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 == 0) {
            q.push(i);
        }
    }
    
    if (q.size() == n) {
        cout << "YES" << endl;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}