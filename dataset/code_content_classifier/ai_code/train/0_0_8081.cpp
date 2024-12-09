#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> segments(m);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        segments[i] = {u, v};
    }
    
    vector<int> result;
    
    for (int i = 0; i < m; i++) {
        vector<bool> seen(n + 1, false);
        
        for (int j = 0; j < m; j++) {
            if (j != i) {
                seen[segments[j][0]] = true;
                seen[segments[j][1]] = true;
            }
        }
        
        bool is_valid = true;
        for (int j = 0; j < m; j++) {
            if (j != i) {
                if (seen[segments[j][0]] == seen[segments[j][1]]) {
                    is_valid = false;
                    break;
                }
            }
        }
        
        if (is_valid) {
            result.push_back(i + 1);
        }
    }
    
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}