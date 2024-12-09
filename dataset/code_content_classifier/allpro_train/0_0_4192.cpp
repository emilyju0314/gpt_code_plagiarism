#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> pipes(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> pipes[i][j];
        }
    }
    
    vector<int> maxFlow(n, 0);
    bool updated = true;
    
    while(updated) {
        updated = false;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int increase = min(k, pipes[i][j] - maxFlow[i]);
                if(pipes[i][j] != 0 && maxFlow[i] + increase > maxFlow[j]) {
                    maxFlow[j] = maxFlow[i] + increase;
                    updated = true;
                }
            }
        }
    }
    
    cout << maxFlow[n-1] << endl;
    
    return 0;
}