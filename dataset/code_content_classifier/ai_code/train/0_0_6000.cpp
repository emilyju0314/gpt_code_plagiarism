#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> computer(n);
    vector<vector<int>> dependencies(n);
    
    for (int i = 0; i < n; i++) {
        cin >> computer[i];
        computer[i]--;
    }
    
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int dep;
            cin >> dep;
            dependencies[i].push_back(dep - 1);
        }
    }
    
    vector<vector<int>> dist(3, vector<int>(n, 0));
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            int max_dep = 0;
            for (int dep : dependencies[j]) {
                max_dep = max(max_dep, dist[i][dep]);
            }
            dist[i][j] = max_dep + 1;
        }
    }
    
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        result = max(result, dist[computer[i]][i]);
    }
    
    cout << result << endl;
    
    return 0;
}