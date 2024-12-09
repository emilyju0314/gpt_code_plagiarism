#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> tree;
vector<int> lights;
vector<int> visited;
vector<int> xorValues;

bool dfs(int node, int parent, int xorValue) {
    visited[node] = 1;
    int expectedParity = xorValue & 1;
    
    for (int child : tree[node]) {
        if (child == parent) continue;
        
        int edgeValue = (lights[child] == -1) ? xorValues[child] ^ xorValue : lights[child];
        if (edgeValue == -1) {
            edgeValue = (1 << 30) - 1; // Set all bits to 1 if value is not known
        }
        
        int newParity = __builtin_popcount(edgeValue) % 2;
        int newXorValue = xorValue ^ edgeValue;
        
        if (visited[child]) {
            if (newParity != expectedParity) {
                return false;
            }
        } else {
            xorValues[child] = newXorValue;
            if (!dfs(child, node, newXorValue)) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        tree.assign(n, vector<int>());
        lights.assign(n, -1);
        visited.assign(n, 0);
        xorValues.assign(n, 0);
        
        for (int i = 0; i < n - 1; i++) {
            int x, y, v;
            cin >> x >> y >> v;
            x--; y--;
            tree[x].push_back(y);
            tree[y].push_back(x);
            lights[i] = v;
        }
        
        if (m == 0) {
            cout << "YES" << endl;
            for (int i = 0; i < n - 1; i++) {
                cout << tree[i][0] + 1 << " " << tree[i][1] + 1 << " " << ((lights[i] == -1) ? 0 : lights[i]) << endl;
            }
        } else {
            bool possible = true;
            for (int i = 0; i < m; i++) {
                int a, b, p;
                cin >> a >> b >> p;
                a--; b--;
                int xorValue = xorValues[a] ^ xorValues[b];
                int expectedParity = xorValue & 1;
                if (expectedParity != p) {
                    possible = false;
                }
            }
            
            if (!possible || !dfs(0, -1, 0)) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                for (int i = 0; i < n - 1; i++) {
                    cout << tree[i][0] + 1 << " " << tree[i][1] + 1 << " " << ((lights[i] == -1) ? xorValues[tree[i][0]] ^ xorValues[tree[i][1]] : lights[i]) << endl;
                }
            }
        }
    }
    
    return 0;
}