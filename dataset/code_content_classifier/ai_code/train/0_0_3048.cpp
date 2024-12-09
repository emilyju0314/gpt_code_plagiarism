#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> adj(n+1);
        vector<int> leafCount(n+1, 0);

        for(int j = 0; j < n-1; j++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        queue<int> leaves;
        for(int j = 1; j <= n; j++) {
            if(adj[j].size() == 1) {
                leaves.push(j);
            }
        }

        int ans = 0;
        while(!leaves.empty()) {
            int count = 0;
            while(!leaves.empty() && count < k) {
                int leaf = leaves.front();
                leaves.pop();
                int parent = adj[leaf][0];
                leafCount[parent]++;
                if(leafCount[parent] == k) {
                    leaves.push(parent);
                    count++;
                }
            }
            ans++;
        }

        cout << ans << endl;
    }
    
    return 0;
}