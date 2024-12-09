#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> edges[n+1];
        vector<pair<int, int>> res;
        
        for(int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
        }
        
        for(int i = 1; i < n; i++) {
            cout << i << " " << i+1 << endl;
        }
    }
    
    return 0;
}