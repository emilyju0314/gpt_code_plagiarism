#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        string s;
        cin >> s;
        
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        
        for(int i=0; i<n; i++) {
            if(s[i] == 'B') {
                min_val = min(min_val, a[i]);
            } else {
                max_val = max(max_val, a[i]);
            }
        }
        
        bool possible = true;
        vector<bool> seen(n, false);
        for(int i=0; i<n; i++) {
            int num = a[i] - min_val;
            if(s[i] == 'B') {
                num = a[i] - max_val + 1;
            }
            if(num < 1 || num > n || seen[num-1]) {
                possible = false;
                break;
            }
            seen[num-1] = true;
        }
        
        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}