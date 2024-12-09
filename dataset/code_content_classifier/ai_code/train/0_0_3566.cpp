#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        vector<int> ans(2*n);
        vector<bool> used(2*n+1, false);
        
        int curr = 1;
        for (int i = 0; i < n; i++) {
            ans[2*i] = b[i];
            used[b[i]] = true;
        }
        
        int idx = 0;
        while (idx < 2*n) {
            if (ans[idx] == 0) {
                while (used[curr]) {
                    curr++;
                }
                ans[idx] = curr;
                used[curr] = true;
            }
            idx++;
        }
        
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (ans[2*i] > b[i] && ans[2*i+1] > b[i]) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            for (int i = 0; i < 2*n; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
        
    }
    
    return 0;
}