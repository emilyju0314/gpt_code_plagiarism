#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> q(n);
        vector<int> minPermutation(n), maxPermutation(n);
        
        for(int i = 0; i < n; i++) {
            cin >> q[i];
        }
        
        int nextMin = 1, nextMax = n;
        
        for(int i = 0; i < n; i++) {
            minPermutation[i] = q[i] == q[i - 1] ? nextMin++ : max(q[i], nextMin);
            maxPermutation[i] = q[i] == q[i - 1] ? --nextMax : min(q[i], nextMax);
        }
        
        for(int i = 0; i < n; i++) {
            cout << minPermutation[i] << " ";
        }
        cout << endl;
        
        for(int i = 0; i < n; i++) {
            cout << maxPermutation[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}