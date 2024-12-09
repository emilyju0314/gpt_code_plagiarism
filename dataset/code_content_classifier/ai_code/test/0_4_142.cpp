#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int m, n;
        cin >> m >> n;
        
        vector<vector<int>> joys(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> joys[i][j];
            }
        }
        
        vector<int> minJoys(n, INT_MAX);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                minJoys[j] = min(minJoys[j], joys[i][j]);
            }
        }
        
        sort(minJoys.begin(), minJoys.end());
        
        cout << minJoys[n-2] << endl;
    }
    
    return 0;
}